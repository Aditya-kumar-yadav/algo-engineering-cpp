#include <gtest/gtest.h>
#include "graphs/1020_number_of_enclaves.hpp" // Strictly pathed and lowercased

TEST(NumberOfEnclavesTest, Example1_SomeEnclaves) {
    Solution sol;
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    EXPECT_EQ(sol.numEnclaves(grid), 3);
}

TEST(NumberOfEnclavesTest, Example2_NoEnclaves) {
    Solution sol;
    std::vector<std::vector<int>> grid = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };
    EXPECT_EQ(sol.numEnclaves(grid), 0);
}

TEST(NumberOfEnclavesTest, AllSea) {
    Solution sol;
    std::vector<std::vector<int>> grid = {
        {0, 0},
        {0, 0}
    };
    EXPECT_EQ(sol.numEnclaves(grid), 0);
}

TEST(NumberOfEnclavesTest, AllLand) {
    Solution sol;
    // Since all land is touching the boundary, none of them are enclaves
    std::vector<std::vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    EXPECT_EQ(sol.numEnclaves(grid), 0);
}

TEST(NumberOfEnclavesTest, PerfectEnclave) {
    Solution sol;
    // The center '1' is completely surrounded by '0's
    std::vector<std::vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    EXPECT_EQ(sol.numEnclaves(grid), 1);
}