#include <gtest/gtest.h>
#include "dp/0329_longest_increasing_path_in_a_matrix.hpp" // Strictly pathed and lowercased

TEST(LongestIncreasingPathinaMatrixTest, Example1) {
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    // The longest increasing path is [1, 2, 6, 9].
    EXPECT_EQ(sol.longestIncreasingPath(matrix), 4);
}

TEST(LongestIncreasingPathinaMatrixTest, Example2) {
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };
    // The longest increasing path is [3, 4, 5, 6].
    EXPECT_EQ(sol.longestIncreasingPath(matrix), 4);
}

TEST(LongestIncreasingPathinaMatrixTest, Example3_SingleElement) {
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {1}
    };
    EXPECT_EQ(sol.longestIncreasingPath(matrix), 1);
}

TEST(LongestIncreasingPathinaMatrixTest, EmptyMatrix) {
    Solution sol;
    std::vector<std::vector<int>> matrix = {};
    EXPECT_EQ(sol.longestIncreasingPath(matrix), 0);
    
    std::vector<std::vector<int>> matrix2 = {{}};
    EXPECT_EQ(sol.longestIncreasingPath(matrix2), 0);
}

TEST(LongestIncreasingPathinaMatrixTest, AllSameElements) {
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    // No strictly increasing path, so max length is just 1 (a single cell).
    EXPECT_EQ(sol.longestIncreasingPath(matrix), 1);
}

TEST(LongestIncreasingPathinaMatrixTest, SnakePath) {
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    // The path winds through every single element: 1->2->3->4->5->6->7->8->9
    EXPECT_EQ(sol.longestIncreasingPath(matrix), 9);
}

TEST(LongestIncreasingPathinaMatrixTest, DecreasingMatrix) {
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    // Path: 1 -> 2 -> 3 -> 6 -> 9 (length 5)
    EXPECT_EQ(sol.longestIncreasingPath(matrix), 5);
}