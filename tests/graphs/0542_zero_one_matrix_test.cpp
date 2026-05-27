#include <gtest/gtest.h>
#include "graphs/0542_zero_one_matrix.hpp" // Strictly pathed and lowercased

TEST(ZeroOneMatrixTest, Example1) {
    Solution sol;
    std::vector<std::vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    EXPECT_EQ(sol.updateMatrix(mat), expected); 
}

TEST(ZeroOneMatrixTest, Example2) {
    Solution sol;
    std::vector<std::vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 2, 1}
    };
    EXPECT_EQ(sol.updateMatrix(mat), expected); 
}

TEST(ZeroOneMatrixTest, AllZeros) {
    Solution sol;
    std::vector<std::vector<int>> mat = {
        {0, 0},
        {0, 0}
    };
    std::vector<std::vector<int>> expected = {
        {0, 0},
        {0, 0}
    };
    EXPECT_EQ(sol.updateMatrix(mat), expected); 
}

TEST(ZeroOneMatrixTest, SingleZeroCorner) {
    // Tests maximum outward expansion across the whole grid
    Solution sol;
    std::vector<std::vector<int>> mat = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 0}
    };
    std::vector<std::vector<int>> expected = {
        {4, 3, 2},
        {3, 2, 1},
        {2, 1, 0}
    };
    EXPECT_EQ(sol.updateMatrix(mat), expected); 
}

TEST(ZeroOneMatrixTest, SingleRowMatrix) {
    // Tests boundary checks heavily on the Y-axis
    Solution sol;
    std::vector<std::vector<int>> mat = {
        {0, 1, 1, 0, 1}
    };
    std::vector<std::vector<int>> expected = {
        {0, 1, 1, 0, 1}
    };
    EXPECT_EQ(sol.updateMatrix(mat), expected); 
}

TEST(ZeroOneMatrixTest, SingleColumnMatrix) {
    // Tests boundary checks heavily on the X-axis
    Solution sol;
    std::vector<std::vector<int>> mat = {
        {1},
        {1},
        {0},
        {1}
    };
    std::vector<std::vector<int>> expected = {
        {2},
        {1},
        {0},
        {1}
    };
    EXPECT_EQ(sol.updateMatrix(mat), expected); 
}

TEST(ZeroOneMatrixTest, CheckerboardPattern) {
    // Tests dense, alternating grids
    Solution sol;
    std::vector<std::vector<int>> mat = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    std::vector<std::vector<int>> expected = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    EXPECT_EQ(sol.updateMatrix(mat), expected); 
}