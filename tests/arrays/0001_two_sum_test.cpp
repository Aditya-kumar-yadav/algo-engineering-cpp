#include <gtest/gtest.h>
#include "arrays/0001_two_sum.hpp"

TEST(TwoSumTest, StandardCase) {
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    std::vector<int> expected = {0, 1};
    EXPECT_EQ(sol.twoSum(nums, 9), expected);
}

TEST(TwoSumTest, UnsortedElements) {
    Solution sol;
    std::vector<int> nums = {3, 2, 4};
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(sol.twoSum(nums, 6), expected);
}

TEST(TwoSumTest, SameElements) {
    Solution sol;
    std::vector<int> nums = {3, 3};
    std::vector<int> expected = {0, 1};
    EXPECT_EQ(sol.twoSum(nums, 6), expected);
}