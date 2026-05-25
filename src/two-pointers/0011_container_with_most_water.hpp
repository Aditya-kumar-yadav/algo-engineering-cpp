/* * ID: 11
 * Title: Container With Most Water
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max and std::min

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        // 1. Use std::size_t for container sizing and indices
        std::size_t left = 0;
        std::size_t right = height.size() - 1;
        
        int max_water = 0;

        while (left < right) {
            // The water height is limited by the shorter line
            int current_height = std::min(height[left], height[right]);
            
            // Cast the difference to int to match the return type
            int current_width = static_cast<int>(right - left);
            int current_area = current_height * current_width;

            // Update max_water if we found a larger container
            max_water = std::max(max_water, current_area);

            // To maximize area, we must move the pointer pointing to the shorter line
            // moving the taller line inward would only decrease the width without increasing the height constraint.
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        // 2. Ensure all code paths return a value
        return max_water;
    }
};