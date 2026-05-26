#include <gtest/gtest.h>
#include "graphs/0733_flood_fill.hpp" // Strictly pathed and lowercased

TEST(FloodFillTest, Example1_StandardFill) {
    Solution sol;
    std::vector<std::vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    std::vector<std::vector<int>> expected = {
        {2, 2, 2},
        {2, 2, 0},
        {2, 0, 1}
    };
    EXPECT_EQ(sol.floodFill(image, 1, 1, 2), expected);
}

TEST(FloodFillTest, Example2_AlreadyTargetColor) {
    Solution sol;
    std::vector<std::vector<int>> image = {
        {0, 0, 0},
        {0, 0, 0}
    };
    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0}
    };
    EXPECT_EQ(sol.floodFill(image, 0, 0, 0), expected);
}