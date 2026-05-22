/* * ID: 26
 * Title: Remove Duplicates from Sorted Array
 * Difficulty: Easy
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // Use size_t for strict compiler compliance with vector sizes
        std::size_t insertIndex = 1;
        
        for (std::size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }
        
        // Safely cast back to int to match LeetCode's expected signature
        return static_cast<int>(insertIndex);
    }
    
};
