/* * ID: 200
 * Title: Number of Islands
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {
    //Funtion to call

    private:
    void dfs(std::vector<std::vector<char>>& grid, std::size_t r, std::size_t c) {
        // Safe unsigned boundary checks
        if (r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }

        // Sink the current land to prevent infinite loops
        grid[r][c] = '0';

        // Traverse all 4 directions. 
        // Explicitly check > 0 before subtracting from size_t to prevent underflow wrap-around.
        if (r > 0) dfs(grid, r - 1, c);                  // Up
        if (r + 1 < grid.size()) dfs(grid, r + 1, c);    // Down
        if (c > 0) dfs(grid, r, c - 1);                  // Left
        if (c + 1 < grid[0].size()) dfs(grid, r, c + 1); // Right
    }
    // main funtion
public:
   int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int num_islands = 0;
        
        // 1. Use std::size_t for looping through container.size()
        for (std::size_t i = 0; i < grid.size(); ++i) {
            for (std::size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    num_islands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        // 2. Ensure all code paths return a value
        return num_islands;
    }
};
