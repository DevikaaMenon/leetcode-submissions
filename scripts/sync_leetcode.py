"""
LeetCode -> GitHub sync (multi-version aware)
-----------------------------------------------
Designed to run inside a GitHub Actions workflow, on a checked-out copy
of the repo. It:

  1. Fetches every ACCEPTED submission from your LeetCode account.
  2. Groups them by problem, keeping every version with genuinely
     different code (so brute force -> better -> optimal all survive
     as separate files instead of overwriting each other).
  3. Writes new versions as Easy|Medium|Hard/<slug>/solution_vN.<ext>
  4. Tracks what's already been synced in sync_state.json so re-runs
     are cheap and idempotent (no duplicate files, no reprocessing).

This script only WRITES to the local working copy. Committing and
pushing is handled by the GitHub Actions workflow (see
.github/workflows/leetcode-sync.yml), so a single commit covers
everything a run adds.
"""

import os
import json
import time
import requests
from pathlib import Path

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

DIFFICULTY_MAP = {1: "Easy", 2: "Medium", 3: "Hard"}

SESSION = requests.Session()
SESSION.cookies.set("LEETCODE_SESSION", LEETCODE_SESSION, domain="leetcode.com")
SESSION.cookies.set("csrftoken", CSRF_TOKEN, domain="leetcode.com")
SESSION.headers.update({
    "Referer": "https://leetcode.com",
    "x-csrftoken": CSRF_TOKEN,
    "User-Agent": "Mozilla/5.0",
})


def load_state():
    if STATE_FILE.exists():
        return json.loads(STATE_FILE.read_text())
    return {}


def save_state(state):
    STATE_FILE.write_text(json.dumps(state, indent=2, sort_keys=True))


def fetch_difficulty_lookup():
    resp = requests.get(
        "https://leetcode.com/api/problems/algorithms/",
        headers={"User-Agent": "Mozilla/5.0"},
    )
    resp.raise_for_status()
    data = resp.json()
    lookup = {}
    for item in data["stat_status_pairs"]:
        slug = item["stat"]["question__title_slug"]
        level = item["difficulty"]["level"]
        lookup[slug] = DIFFICULTY_MAP.get(level, "Unknown")
    return lookup


def fetch_all_accepted():
    """Returns {slug: [submission, ...]} in chronological order (oldest first)."""
    by_slug = {}
    offset, limit = 0, 20
    while True:
        resp = SESSION.get(
            "https://leetcode.com/api/submissions/",
            params={"offset": offset, "limit": limit},
        )
        resp.raise_for_status()
        data = resp.json()
        subs = data.get("submissions_dump", [])
        if not subs:
            break
        for sub in subs:
            if sub.get("status_display") != "Accepted":
                continue
            by_slug.setdefault(sub["title_slug"], []).append(sub)
        if not data.get("has_next"):
            break
        offset += limit
        time.sleep(0.4)

    for slug in by_slug:
        by_slug[slug].sort(key=lambda s: int(s["timestamp"]))
    return by_slug


def main():
    print("Fetching difficulty data...")
    difficulty_lookup = fetch_difficulty_lookup()

    print("Fetching accepted submissions...")
    submissions_by_slug = fetch_all_accepted()

    state = load_state()
    new_files = []
    touched_slugs = []

    for slug, subs in submissions_by_slug.items():
        difficulty = difficulty_lookup.get(slug, "Unknown")
        problem_dir = REPO_ROOT / difficulty / slug
        slug_state = state.setdefault(slug, {"synced_ids": [], "versions": []})

        for sub in subs:
            sub_id = str(sub["id"])
            if sub_id in slug_state["synced_ids"]:
                continue

            code = (sub.get("code") or "").strip()
            if not code:
                continue

            code_hash = hash(code)
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
                "runtime": sub.get("time") or sub.get("status_runtime") or "N/A",
                "memory": sub.get("memory") or sub.get("status_memory") or "N/A",
                "lang": sub.get("lang", "?"),
                "code_hash": code_hash,
            }
            slug_state["versions"].append(entry)
            slug_state["synced_ids"].append(sub_id)

            new_files.append(str(file_path.relative_to(REPO_ROOT)))
            if slug not in touched_slugs:
                touched_slugs.append(slug)

    save_state(state)

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
