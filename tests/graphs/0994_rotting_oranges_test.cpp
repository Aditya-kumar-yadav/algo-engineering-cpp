#include <gtest/gtest.h>
#include "graphs/0994_rotting_oranges.hpp" // Strictly pathed and lowercased

TEST(RottingOrangesTest, Example1_CanRotAll) {
    Solution sol;
    std::vector<std::vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    EXPECT_EQ(sol.orangesRotting(grid), 4);
}

TEST(RottingOrangesTest, Example2_ImpossibleToRotAll) {
    Solution sol;
    std::vector<std::vector<int>> grid = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}
    };
    EXPECT_EQ(sol.orangesRotting(grid), -1);
}

TEST(RottingOrangesTest, Example3_AlreadyEmpty) {
    Solution sol;
    std::vector<std::vector<int>> grid = {
        {0, 2}
    };
    EXPECT_EQ(sol.orangesRotting(grid), 0);
}