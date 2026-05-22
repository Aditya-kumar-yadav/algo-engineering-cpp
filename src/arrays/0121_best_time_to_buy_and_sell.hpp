/* * ID: 121 
 * Title: Best Time to Buy and Sell Stock 
 * Difficulty: Easy 
 * Companies: Amazon, Google , Facebook, Apple, Adobe, Oracle, Uber, Airbnb, Twitter, LinkedIn, Salesforce, Dropbox, eBay, PayPal, Intel, IBM, Cisco, Netflix
 */
#pragma once
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int minPrice = prices[0];
        int maxProf = 0;
        
        // Fix 1: Use std::size_t for loop index
        for (std::size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > maxProf) {
                maxProf = prices[i] - minPrice;
            }
        }
        
        return maxProf;
    }
};