#include <gtest/gtest.h>
#include "graphs/0130_surrounded_regions.hpp" // Strictly pathed and lowercased

TEST(SurroundedRegionsTest, Example1_StandardCapture) {
    Solution sol;
    std::vector<std::vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    std::vector<std::vector<char>> expected = {
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    
    sol.solve(board);
    EXPECT_EQ(board, expected);
}

TEST(SurroundedRegionsTest, Example2_SingleCell) {
    Solution sol;
    std::vector<std::vector<char>> board = {{'X'}};
    std::vector<std::vector<char>> expected = {{'X'}};
    
    sol.solve(board);
    EXPECT_EQ(board, expected);
}

TEST(SurroundedRegionsTest, EmptyBoard) {
    Solution sol;
    std::vector<std::vector<char>> board = {};
    std::vector<std::vector<char>> expected = {};
    
    sol.solve(board);
    EXPECT_EQ(board, expected);
}

TEST(SurroundedRegionsTest, AllO_NoCapture) {
    Solution sol;
    std::vector<std::vector<char>> board = {
        {'O', 'O', 'O'},
        {'O', 'O', 'O'},
        {'O', 'O', 'O'}
    };
    std::vector<std::vector<char>> expected = {
        {'O', 'O', 'O'},
        {'O', 'O', 'O'},
        {'O', 'O', 'O'}
    };
    
    sol.solve(board);
    EXPECT_EQ(board, expected);
}

TEST(SurroundedRegionsTest, ConnectedToEdge_NoCapture) {
    Solution sol;
    // The inner 'O' connects to the top edge 'O', so it cannot be surrounded
    std::vector<std::vector<char>> board = {
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X'}
    };
    std::vector<std::vector<char>> expected = {
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X'}
    };
    
    sol.solve(board);
    EXPECT_EQ(board, expected);
}