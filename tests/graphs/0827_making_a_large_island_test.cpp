#include <gtest/gtest.h>
#include <vector>
#include "graphs/0827_making_a_large_island.hpp"

TEST(MakingALargeIslandTest, AllOnesLargeGrid) {
    Solution sol;
    std::vector<std::vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    EXPECT_EQ(sol.largestIsland(grid), 9);
}

TEST(MakingALargeIslandTest, SingleZero) {
    Solution sol;
    std::vector<std::vector<int>> grid = {{0}};
    EXPECT_EQ(sol.largestIsland(grid), 1);
}

TEST(MakingALargeIslandTest, SingleOne) {
    Solution sol;
    std::vector<std::vector<int>> grid = {{1}};
    EXPECT_EQ(sol.largestIsland(grid), 1);
}

TEST(MakingALargeIslandTest, ConnectFourSeparateIslands) {
    Solution sol;
    std::vector<std::vector<int>> grid = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    EXPECT_EQ(sol.largestIsland(grid), 5);
}

TEST(MakingALargeIslandTest, OptimalStrategicFlip) {
    Solution sol;
    std::vector<std::vector<int>> grid = {
        {1, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 1}
    };
    EXPECT_EQ(sol.largestIsland(grid), 7);
}

TEST(MakingALargeIslandTest, LargeAllZeros) {
    Solution sol;
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    EXPECT_EQ(sol.largestIsland(grid), 1);
}