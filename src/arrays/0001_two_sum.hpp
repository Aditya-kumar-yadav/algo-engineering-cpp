/* * ID: 1 
 * Title: Two Sum 
 * Difficulty: Easy 
 * Companies: Amazon, Microsoft , Google, Facebook, Apple, Adobe, Oracle, Uber, Airbnb, Twitter, LinkedIn, Salesforce, Dropbox, eBay, PayPal, Intel, IBM, Cisco, Netflix
 */
#pragma once
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        
        // Fix 1: Use std::size_t instead of int to match nums.size()
        for (std::size_t i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            if (numMap.count(complement)) {
                // Fix 2: Cast the size_t back to int because the return type demands vector<int>
                return {numMap[complement], static_cast<int>(i)};
            }
            numMap[nums[i]] = static_cast<int>(i);
        }
        
        // Fix 3: Provide a default return to prevent "control reaches end of non-void function"
        return {}; 
    }
};