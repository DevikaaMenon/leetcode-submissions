"""
Slug -> pattern-folder mapping for the LeetCode sync script.

New problems not yet listed here land in an "Uncategorized" folder;
sync_leetcode.py prints a warning listing them so entries can be
added by hand.
"""

PATTERN_MAP = {
    # Arrays & Hashing
    "concatenation-of-array": "Arrays & Hashing",
    "contains-duplicate": "Arrays & Hashing",
    "find-all-numbers-disappeared-in-an-array": "Arrays & Hashing",
    "find-missing-and-repeated-values": "Arrays & Hashing",
    "group-anagrams": "Arrays & Hashing",
    "longest-common-prefix": "Arrays & Hashing",
    "longest-consecutive-sequence": "Arrays & Hashing",
    "majority-element": "Arrays & Hashing",
    "max-consecutive-ones": "Arrays & Hashing",
    "missing-number": "Arrays & Hashing",
    "product-of-array-except-self": "Arrays & Hashing",
    "rotate-array": "Arrays & Hashing",
    "set-mismatch": "Arrays & Hashing",
    "shuffle-the-array": "Arrays & Hashing",
    "top-k-frequent-elements": "Arrays & Hashing",
    "two-sum": "Arrays & Hashing",
    "valid-anagram": "Arrays & Hashing",
    "valid-sudoku": "Arrays & Hashing",
    "how-many-numbers-are-smaller-than-the-current-number": "Arrays & Hashing",
    "find-the-largest-almost-missing-integer": "Arrays & Hashing",
    "smallest-missing-integer-greater-than-sequential-prefix-sum": "Arrays & Hashing",
    "monotonic-array": "Arrays & Hashing",
    "count-hills-and-valleys-in-an-array": "Arrays & Hashing",
    "find-missing-elements": "Arrays & Hashing",
    "longest-balanced-subarray-i": "Arrays & Hashing",

    # Two Pointers
    "merge-sorted-array": "Two Pointers",
    "move-zeroes": "Two Pointers",
    "rearrange-array-elements-by-sign": "Two Pointers",
    "merge-strings-alternately": "Two Pointers",
    "reverse-vowels-of-a-string": "Two Pointers",
    "reverse-string": "Two Pointers",
    "valid-palindrome": "Two Pointers",
    "valid-palindrome-ii": "Two Pointers",
    "3sum": "Two Pointers",
    "container-with-most-water": "Two Pointers",
    "trapping-rain-water": "Two Pointers",
    "two-sum-ii-input-array-is-sorted": "Two Pointers",
    "sort-colors": "Two Pointers",
    "reverse-words-in-a-string": "Two Pointers",
    "remove-duplicates-from-sorted-array": "Two Pointers",

    # Sliding Window
    "best-time-to-buy-and-sell-stock": "Sliding Window",
    "longest-substring-without-repeating-characters": "Sliding Window",
    "longest-repeating-character-replacement": "Sliding Window",
    "maximum-length-substring-with-two-occurrences": "Sliding Window",

    # Stack
    "valid-parentheses": "Stack",
    "min-stack": "Stack",
    "evaluate-reverse-polish-notation": "Stack",
    "decode-string": "Stack",

    # Binary Search
    "find-first-and-last-position-of-element-in-sorted-array": "Binary Search",
    "find-k-closest-elements": "Binary Search",
    "find-minimum-in-rotated-sorted-array": "Binary Search",
    "search-in-rotated-sorted-array": "Binary Search",
    "search-a-2d-matrix": "Binary Search",
    "koko-eating-bananas": "Binary Search",
    "sqrtx": "Binary Search",

    # Linked List
    "linked-list-cycle": "Linked List",
    "add-two-numbers": "Linked List",
    "merge-two-sorted-lists": "Linked List",
    "middle-of-the-linked-list": "Linked List",
    "remove-nth-node-from-end-of-list": "Linked List",
    "reorder-list": "Linked List",
    "reverse-linked-list": "Linked List",

    # Trees
    "balanced-binary-tree": "Trees",
    "binary-tree-inorder-traversal": "Trees",
    "binary-tree-level-order-traversal": "Trees",
    "binary-tree-maximum-path-sum": "Trees",
    "binary-tree-postorder-traversal": "Trees",
    "binary-tree-preorder-traversal": "Trees",
    "binary-tree-right-side-view": "Trees",
    "construct-binary-tree-from-preorder-and-inorder-traversal": "Trees",
    "invert-binary-tree": "Trees",
    "kth-smallest-element-in-a-bst": "Trees",
    "lowest-common-ancestor-of-a-binary-search-tree": "Trees",
    "maximum-depth-of-binary-tree": "Trees",
    "same-tree": "Trees",
    "search-in-a-binary-search-tree": "Trees",
    "symmetric-tree": "Trees",
    "validate-binary-search-tree": "Trees",

    # Tries
    "implement-trie-prefix-tree": "Tries",

    # Heap - Priority Queue
    "find-median-from-data-stream": "Heap - Priority Queue",
    "k-closest-points-to-origin": "Heap - Priority Queue",
    "kth-largest-element-in-an-array": "Heap - Priority Queue",

    # Backtracking
    "combination-sum": "Backtracking",
    "subsets": "Backtracking",
    "permutations": "Backtracking",

    # Graphs
    "number-of-islands": "Graphs",
    "max-area-of-island": "Graphs",
    "course-schedule-iv": "Graphs",

    # 1-D DP
    "climbing-stairs": "1-D DP",
    "min-cost-climbing-stairs": "1-D DP",
    "n-th-tribonacci-number": "1-D DP",
    "fibonacci-number": "1-D DP",
    "house-robber": "1-D DP",
    "coin-change": "1-D DP",
    "coin-change-ii": "1-D DP",
    "pascals-triangle": "1-D DP",
    "pascals-triangle-ii": "1-D DP",
    "maximum-subarray": "1-D DP",

    # 2-D DP
    "longest-common-subsequence": "2-D DP",
    "unique-paths": "2-D DP",
    "stone-game": "2-D DP",
    "longest-palindromic-substring": "2-D DP",

    # Greedy
    "minimum-cost-of-buying-candies-with-discount": "Greedy",
    "minimum-number-game": "Greedy",

    # Math & Geometry
    "add-digits": "Math & Geometry",
    "concatenate-non-zero-digits-and-multiply-by-sum-i": "Math & Geometry",
    "concatenate-non-zero-digits-and-multiply-by-sum-ii": "Math & Geometry",
    "gcd-of-odd-and-even-sums": "Math & Geometry",
    "check-if-two-chessboard-squares-have-the-same-color": "Math & Geometry",
    "even-number-of-knight-moves": "Math & Geometry",
    "count-square-sum-triples": "Math & Geometry",
    "excel-sheet-column-title": "Math & Geometry",
    "number-of-elapsed-seconds-between-two-times": "Math & Geometry",
    "fizz-buzz": "Math & Geometry",
    "ugly-number": "Math & Geometry",
    "integer-to-roman": "Math & Geometry",
    "palindrome-number": "Math & Geometry",
    "largest-palindromic-number": "Math & Geometry",
    "nim-game": "Math & Geometry",
    "check-if-it-is-a-good-array": "Math & Geometry",

    # Bit Manipulation
    "power-of-two": "Bit Manipulation",

    # Database
    "article-views-i": "Database",
    "big-countries": "Database",
    "find-customer-referee": "Database",
    "invalid-tweets": "Database",
    "recyclable-and-low-fat-products": "Database",
}
