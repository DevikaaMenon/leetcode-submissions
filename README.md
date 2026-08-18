# leetcode-submissions
A collection of questions I have solved on leetcode

## Structure

```
<pattern>/
  <problem-slug>/
    solution_v1.cpp
    ...
```

Solutions are grouped by pattern (Arrays & Hashing, Two Pointers, Sliding Window, Stack, Binary Search, Linked List, Trees, Tries, Heap - Priority Queue, Backtracking, Graphs, 1-D DP, 2-D DP, Greedy, Math & Geometry, Bit Manipulation, Database).

`scripts/sync_leetcode.py` pulls accepted submissions from LeetCode and files new ones into the matching pattern folder via `scripts/pattern_map.py`. Problems not yet in that map land in `Uncategorized/` until sorted by hand.
