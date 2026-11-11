"""
LeetCode -> GitHub sync (multi-version aware)
-----------------------------------------------
Designed to run inside a GitHub Actions workflow, on a checked-out copy
of the repo. It:

  1. Fetches every ACCEPTED submission from your LeetCode account.
  2. Groups them by problem, keeping every version with genuinely
     different code (so brute force -> better -> optimal all survive
     as separate files instead of overwriting each other).
  3. Writes new versions as <pattern>/<slug>/solution_vN.<ext>, where
     <pattern> comes from PATTERN_MAP in pattern_map.py (falls back to
     "Uncategorized" for problems not yet mapped there).
  4. Tracks what's already been synced in sync_state.json so re-runs
     are cheap and idempotent (no duplicate files, no reprocessing).

This script only WRITES to the local working copy. Committing and
pushing is handled by the GitHub Actions workflow (see
.github/workflows/leetcode-sync.yml), so a single commit covers
everything a run adds.
"""

import os
import json
import hashlib
import time
import requests
from pathlib import Path

from pattern_map import PATTERN_MAP

REPO_ROOT = Path(__file__).resolve().parent.parent
STATE_FILE = REPO_ROOT / "sync_state.json"

LEETCODE_SESSION = os.environ["LEETCODE_SESSION"]
CSRF_TOKEN = os.environ["CSRF_TOKEN"]

LANG_EXT = {
    "python": "py", "python3": "py", "java": "java", "c": "c", "cpp": "cpp",
    "csharp": "cs", "javascript": "js", "typescript": "ts", "kotlin": "kt",
    "swift": "swift", "golang": "go", "ruby": "rb", "scala": "scala",
    "rust": "rs", "php": "php", "mysql": "sql", "elixir": "ex",
    "racket": "rkt", "erlang": "erl", "dart": "dart",
}

SESSION = requests.Session()
SESSION.cookies.set("LEETCODE_SESSION", LEETCODE_SESSION, domain="leetcode.com")
SESSION.cookies.set("csrftoken", CSRF_TOKEN, domain="leetcode.com")
SESSION.headers.update({
    "Referer": "https://leetcode.com",
    "x-csrftoken": CSRF_TOKEN,
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
                  "(KHTML, like Gecko) Chrome/120.0 Safari/537.36",
    "Accept": "application/json, text/plain, */*",
})


def load_state():
    if STATE_FILE.exists():
        return json.loads(STATE_FILE.read_text())
    return {}


def save_state(state):
    STATE_FILE.write_text(json.dumps(state, indent=2, sort_keys=True))


GRAPHQL_URL = "https://leetcode.com/graphql"

SUBMISSION_LIST_QUERY = """
query submissionList($offset: Int!, $limit: Int!) {
  submissionList(offset: $offset, limit: $limit) {
    hasNext
    submissions { id statusDisplay lang timestamp titleSlug }
  }
}
"""

SUBMISSION_DETAILS_QUERY = """
query submissionDetails($submissionId: Int!) {
  submissionDetails(submissionId: $submissionId) {
    code runtimeDisplay memoryDisplay
  }
}
"""


def graphql(query, variables):
    resp = SESSION.post(GRAPHQL_URL, json={"query": query, "variables": variables})
    resp.raise_for_status()
    body = resp.json()
    if body.get("errors"):
        raise RuntimeError(f"LeetCode GraphQL error: {body['errors']}")
    return body["data"]


def fetch_all_accepted():
    """Returns {slug: [submission, ...]} in chronological order (oldest first).

    Uses the GraphQL API; the old /api/submissions/ REST endpoint is now
    behind a Cloudflare challenge. Code is NOT included here -- it's fetched
    per submission via fetch_details() only for submissions not yet synced.
    """
    by_slug = {}
    offset, limit = 0, 20
    while True:
        data = graphql(SUBMISSION_LIST_QUERY, {"offset": offset, "limit": limit})
        page = data["submissionList"]
        subs = page.get("submissions") or []
        for sub in subs:
            if sub.get("statusDisplay") != "Accepted":
                continue
            by_slug.setdefault(sub["titleSlug"], []).append(sub)
        if not subs or not page.get("hasNext"):
            break
        offset += limit
        time.sleep(0.4)

    for slug in by_slug:
        by_slug[slug].sort(key=lambda s: int(s["timestamp"]))
    return by_slug


def fetch_details(sub_id):
    time.sleep(0.4)
    return graphql(SUBMISSION_DETAILS_QUERY, {"submissionId": int(sub_id)})["submissionDetails"] or {}


def main():
    print("Fetching accepted submissions...")
    submissions_by_slug = fetch_all_accepted()

    state = load_state()
    new_files = []
    touched_slugs = []
    uncategorized_slugs = []

    for slug, subs in submissions_by_slug.items():
        pattern = PATTERN_MAP.get(slug)
        if pattern is None:
            pattern = "Uncategorized"
            uncategorized_slugs.append(slug)
        problem_dir = REPO_ROOT / pattern / slug
        slug_state = state.setdefault(slug, {"synced_ids": [], "versions": []})

        for sub in subs:
            sub_id = str(sub["id"])
            if sub_id in slug_state["synced_ids"]:
                continue

            details = fetch_details(sub_id)
            code = (details.get("code") or "").strip()
            if not code:
                continue

            code_hash = hashlib.sha256(code.encode("utf-8")).hexdigest()
            if any(v["code_hash"] == code_hash for v in slug_state["versions"]):
                slug_state["synced_ids"].append(sub_id)
                continue

            version_num = len(slug_state["versions"]) + 1
            ext = LANG_EXT.get(sub.get("lang", ""), "txt")
            problem_dir.mkdir(parents=True, exist_ok=True)
            file_path = problem_dir / f"solution_v{version_num}.{ext}"
            file_path.write_text(code)

            entry = {
                "id": sub_id,
                "version": version_num,
                "date": time.strftime("%Y-%m-%d", time.gmtime(int(sub["timestamp"]))),
                "runtime": details.get("runtimeDisplay") or "N/A",
                "memory": details.get("memoryDisplay") or "N/A",
                "lang": sub.get("lang", "?"),
                "code_hash": code_hash,
            }
            slug_state["versions"].append(entry)
            slug_state["synced_ids"].append(sub_id)

            new_files.append(str(file_path.relative_to(REPO_ROOT)))
            if slug not in touched_slugs:
                touched_slugs.append(slug)

    save_state(state)

    if uncategorized_slugs:
        print(f"NOTE: {len(uncategorized_slugs)} problem(s) have no entry in "
              f"pattern_map.py and were filed under Uncategorized/: "
              f"{', '.join(sorted(set(uncategorized_slugs)))}")

    if new_files:
        print(f"Added {len(new_files)} new solution file(s) across "
              f"{len(touched_slugs)} problem(s):")
        for f in new_files:
            print(f"  {f}")
        summary = f"Sync: added {len(new_files)} new solution(s) across {len(touched_slugs)} problem(s)"
        (REPO_ROOT / ".commit_message.txt").write_text(summary)
    else:
        print("Nothing new to sync.")
        cm = REPO_ROOT / ".commit_message.txt"
        if cm.exists():
            cm.unlink()


if __name__ == "__main__":
    main()
