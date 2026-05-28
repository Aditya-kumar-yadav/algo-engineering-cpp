/* * ID: 1020
 * Title: Number of Enclaves
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>

class Solution {
private:
    void dfs(std::vector<std::vector<int>>& grid, std::size_t r, std::size_t c) {
        std::size_t m = grid.size();
        std::size_t n = grid[0].size();

        // Base case: out of bounds or water (0)
        if (r >= m || c >= n || grid[r][c] == 0) {
            return;
        }

        // "Sink" the land since it is connected to the boundary
        grid[r][c] = 0;

        // Recursively visit 4-directional neighbors
        // Strict > 0 checks guard against std::size_t underflow
        if (r > 0)     dfs(grid, r - 1, c);
        if (r + 1 < m) dfs(grid, r + 1, c);
        if (c > 0)     dfs(grid, r, c - 1);
        if (c + 1 < n) dfs(grid, r, c + 1);
    }

public:
    int numEnclaves(std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        std::size_t m = grid.size();
        std::size_t n = grid[0].size();

        // 1. Traverse left and right boundaries
        for (std::size_t i = 0; i < m; ++i) {
            if (grid[i][0] == 1)     dfs(grid, i, 0);
            if (grid[i][n - 1] == 1) dfs(grid, i, n - 1);
        }

        // 2. Traverse top and bottom boundaries
        for (std::size_t j = 0; j < n; ++j) {
            if (grid[0][j] == 1)     dfs(grid, 0, j);
            if (grid[m - 1][j] == 1) dfs(grid, m - 1, j);
        }

        // 3. Count remaining enclaves (land not connected to boundaries)
        int enclaves = 0;
        for (std::size_t i = 0; i < m; ++i) {
            for (std::size_t j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};