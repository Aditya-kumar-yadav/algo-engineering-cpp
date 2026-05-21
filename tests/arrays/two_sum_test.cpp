#include <gtest/gtest.h>
#include "arrays/0001_two_sum.hpp"

TEST(TwoSumTest, HandlesStandardCase) {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> expected = {0, 1};
    EXPECT_EQ(sol.twoSum(nums, 9), expected);
}

TEST(TwoSumTest, HandlesNegativeNumbers) {
    Solution sol;
    vector<int> nums = {-1, -2, -3, -4, -5};
    vector<int> expected = {2, 4};
    EXPECT_EQ(sol.twoSum(nums, -8), expected);
}