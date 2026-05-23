#include <gtest/gtest.h>
#include "graphs/0200_number_of_islands.hpp" // Strictly pathed and lowercased

TEST(NumberofIslandsTest, DefaultTest) {
    Solution sol;
    
    std::vector<std::vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    EXPECT_EQ(sol.numIslands(grid), 1);
}

TEST(NumberofIslandsTest, MultipleSeparateIslands) {
    Solution sol;
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    EXPECT_EQ(sol.numIslands(grid), 3);
}

TEST(NumberofIslandsTest, EmptyGrid) {
    Solution sol;
    std::vector<std::vector<char>> grid = {};
    EXPECT_EQ(sol.numIslands(grid), 0);
}

TEST(NumberofIslandsTest, AllWater) {
    Solution sol;
    std::vector<std::vector<char>> grid = {
        {'0', '0', '0'},
        {'0', '0', '0'},
        {'0', '0', '0'}
    };
    EXPECT_EQ(sol.numIslands(grid), 0);
}

TEST(NumberofIslandsTest, AllLand) {
    Solution sol;
    std::vector<std::vector<char>> grid = {
        {'1', '1'},
        {'1', '1'}
    };
    EXPECT_EQ(sol.numIslands(grid), 1);
}

TEST(NumberofIslandsTest, DiagonalIslands) {
    Solution sol;
    // Diagonals do not connect islands, so this should be 4 distinct islands.
    std::vector<std::vector<char>> grid = {
        {'1', '0', '1'},
        {'0', '1', '0'},
        {'1', '0', '1'}
    };
    EXPECT_EQ(sol.numIslands(grid), 5); // 5 distinct '1's separated by '0's
}

TEST(NumberofIslandsTest, SingleColumnGrid) {
    Solution sol;
    std::vector<std::vector<char>> grid = {
        {'1'},
        {'0'},
        {'1'},
        {'1'}
    };
    EXPECT_EQ(sol.numIslands(grid), 2);
}
