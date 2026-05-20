#include <iostream>
#include <vector>
#include <unordered_map>

bool canSplitArray(const std::vector<int>& nums) {
    std::unordered_map<int, int> counts;
    for (int num : nums) {
        counts[num]++;
        if (counts[num] > 2) return false;
    }
    return true;
}