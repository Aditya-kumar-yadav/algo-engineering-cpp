#include <gtest/gtest.h>
#include <vector>
#include "two-pointers/0011_container_with_most_water.hpp" 

// 1. Standard LeetCode Examples
TEST(ContainerWithMostWaterTest, LeetCodeExample1) {
    Solution sol;
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    EXPECT_EQ(sol.maxArea(height), 49);
}

TEST(ContainerWithMostWaterTest, LeetCodeExample2) {
    Solution sol;
    std::vector<int> height = {1, 1};
    EXPECT_EQ(sol.maxArea(height), 1);
}

// 2. Edge Cases (Based on Constraints: n >= 2, height >= 0)
TEST(ContainerWithMostWaterTest, MinimumConstraintZeroHeights) {
    Solution sol;
    std::vector<int> height = {0, 0};
    EXPECT_EQ(sol.maxArea(height), 0);
}

// 3. Pattern: Flat/Uniform Heights
TEST(ContainerWithMostWaterTest, FlatHeights) {
    Solution sol;
    std::vector<int> height = {5, 5, 5, 5, 5};
    // The max area is between the first and last elements: 5 * (4 - 0) = 20
    EXPECT_EQ(sol.maxArea(height), 20); 
}

// 4. Pattern: Strictly Increasing/Decreasing
TEST(ContainerWithMostWaterTest, IncreasingHeights) {
    Solution sol;
    std::vector<int> height = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Max area is formed by indices 1 and 8: height 2 * width 7 = 14
    // Or indices 4 and 8: height 5 * width 4 = 20
    EXPECT_EQ(sol.maxArea(height), 20); 
}

// 5. Pattern: Tall Pillars at the Edges
TEST(ContainerWithMostWaterTest, DistantTallPillars) {
    Solution sol;
    std::vector<int> height = {100, 2, 3, 4, 5, 6, 7, 100};
    // The outer pillars completely dominate the area calculation: 100 * 7 = 700
    EXPECT_EQ(sol.maxArea(height), 700);
}

// 6. Pattern: Tall Pillars in the Middle
TEST(ContainerWithMostWaterTest, CenteredTallPillars) {
    Solution sol;
    std::vector<int> height = {1, 2, 100, 100, 2, 1};
    // The two 100s in the middle form an area of 100 * 1 = 100
    EXPECT_EQ(sol.maxArea(height), 100);
}