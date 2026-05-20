# Split the Array

## 🔗 LeetCode Link
[https://leetcode.com/problems/split-the-array/](https://leetcode.com/problems/split-the-array/)

## 📝 Description
You are given an integer array `nums` of even length. You have to split the array into two parts `nums1` and `nums2` such that:
- `nums1.length == nums2.length == nums.length / 2`
- `nums1` should contain distinct elements.
- `nums2` should also contain distinct elements.

Return `true` if it is possible to split the array, and `false` otherwise.

## 💡 Examples

**Example 1:**
- **Input:** `nums = [1,1,2,2,3,4]`
- **Output:** `true`
- **Explanation:** One possible split is `nums1 = [1,2,3]` and `nums2 = [1,2,4]`. Both contain distinct elements.

**Example 2:**
- **Input:** `nums = [1,1,1,1]`
- **Output:** `false`
- **Explanation:** The only split is `nums1 = [1,1]` and `nums2 = [1,1]`. Neither contains distinct elements.

## ⚙️ Constraints
- `nums.length` is even.
- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`

## ⏱️ Complexity
| Metric | Complexity |
| :--- | :--- |
| **Time** | O(n) |
| **Space** | O(1) |

## 💡 Notes
- To satisfy the condition, each element can appear at most twice in the total array. 
- If any element appears more than twice, it is impossible to distribute them into two arrays such that both have distinct elements.
- We can use a frequency map or a simple array count to verify that no element exceeds a frequency of 2.

---
*Status: [Verified by CI/CD Pipeline ✅]*
