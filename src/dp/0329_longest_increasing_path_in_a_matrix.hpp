/* * ID: 329
 * Title: Longest Increasing Path in a Matrix
 * Difficulty: Hard
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        std::size_t m = matrix.size();
        std::size_t n = matrix[0].size();
        
        // Memoization table to store the longest path starting from each cell
        std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
        int max_len = 0;
        
        // 1. Use std::size_t for looping through container.size()
        for (std::size_t i = 0; i < m; ++i) {
            for (std::size_t j = 0; j < n; ++j) {
                max_len = std::max(max_len, dfs(matrix, i, j, memo));
            }
        }
        
        return max_len;
    }
    
private:
    int dfs(const std::vector<std::vector<int>>& matrix, std::size_t r, std::size_t c, std::vector<std::vector<int>>& memo) {
        // Return precomputed result if available
        if (memo[r][c] != 0) {
            return memo[r][c];
        }
        
        int max_path = 1;
        std::size_t m = matrix.size();
        std::size_t n = matrix[0].size();
        
        // Safely check all four directions using std::size_t boundaries
        
        // Up
        if (r > 0 && matrix[r - 1][c] > matrix[r][c]) {
            max_path = std::max(max_path, 1 + dfs(matrix, r - 1, c, memo));
        }
        // Down
        if (r + 1 < m && matrix[r + 1][c] > matrix[r][c]) {
            max_path = std::max(max_path, 1 + dfs(matrix, r + 1, c, memo));
        }
        // Left
        if (c > 0 && matrix[r][c - 1] > matrix[r][c]) {
            max_path = std::max(max_path, 1 + dfs(matrix, r, c - 1, memo));
        }
        // Right
        if (c + 1 < n && matrix[r][c + 1] > matrix[r][c]) {
            max_path = std::max(max_path, 1 + dfs(matrix, r, c + 1, memo));
        }
        
        // Cache the result before returning
        memo[r][c] = max_path;
        
        // 2. Ensure all code paths return a value
        return max_path;
    }
};