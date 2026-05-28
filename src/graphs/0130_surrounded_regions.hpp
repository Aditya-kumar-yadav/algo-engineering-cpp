/* * ID: 130
 * Title: Surrounded Regions
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    void dfs(std::vector<std::vector<char>>& board, std::size_t r, std::size_t c) {
        std::size_t m = board.size();
        std::size_t n = board[0].size();

        // Base case: out of bounds or not an 'O'
        if (r >= m || c >= n || board[r][c] != 'O') {
            return;
        }

        // Mark the current cell as 'T' (Temporary / Safe)
        // to indicate it's connected to an edge 'O'
        board[r][c] = 'T';

        // Recursively visit all 4 adjacent cells
        // Using strict > 0 checks before subtracting to prevent std::size_t underflow
        if (r > 0)     dfs(board, r - 1, c);
        if (r + 1 < m) dfs(board, r + 1, c);
        if (c > 0)     dfs(board, r, c - 1);
        if (c + 1 < n) dfs(board, r, c + 1);
    }

public:
    void solve(std::vector<std::vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        std::size_t m = board.size();
        std::size_t n = board[0].size();

        // 1. Scan the left and right boundaries
        for (std::size_t i = 0; i < m; ++i) {
            if (board[i][0] == 'O')     dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }

        // 2. Scan the top and bottom boundaries
        for (std::size_t j = 0; j < n; ++j) {
            if (board[0][j] == 'O')     dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }

        // 3. Traverse the entire board to finalize the state
        for (std::size_t i = 0; i < m; ++i) {
            for (std::size_t j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    // This 'O' was not connected to any boundary, so it is surrounded
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    // This was an 'O' connected to a boundary, revert it back
                    board[i][j] = 'O';
                }
            }
        }
    }
};