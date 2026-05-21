# 14. Longest Common Prefix

## Problem Statement
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string `""`.

### Example 1:
* **Input:** `strs = ["flower","flow","flight"]`
* **Output:** `"fl"`

### Example 2:
* **Input:** `strs = ["dog","racecar","car"]`
* **Output:** `""`
* **Explanation:** There is no common prefix among the input strings.

## Constraints
* `1 <= strs.length <= 200`
* `0 <= strs[i].length <= 200`
* `strs[i]` consists of only lowercase English letters.

## Solution & Complexity
* **Time Complexity:** O(N * M * log(N)) - Where `N` is the number of strings and `M` is the maximum length of a string, due to sorting.
* **Space Complexity:** O(1) or O(M) depending on the sorting algorithm overhead used by the compiler.

## How to Test Locally
1. **Compile the code:**
   ```bash
   g++ solution.cpp -o solution