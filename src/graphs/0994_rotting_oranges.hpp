/* * ID: 994
 * Title: Rotting Oranges
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) return 0;

        std::size_t m = grid.size();
        std::size_t n = grid[0].size();
        std::queue<std::pair<std::size_t, std::size_t>> q;
        int fresh_oranges = 0;

        // Step 1: Initialize the queue with all rotten oranges and count fresh ones
        for (std::size_t i = 0; i < m; ++i) {
            for (std::size_t j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }

        // If there are no fresh oranges to begin with, it takes 0 minutes
        if (fresh_oranges == 0) return 0;

        int minutes_passed = 0;
        
        // Directions for 4-directional adjacency: Up, Down, Left, Right
        std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 2: Perform BFS level by level
        while (!q.empty() && fresh_oranges > 0) {
            std::size_t level_size = q.size();
            
            for (std::size_t i = 0; i < level_size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& d : dirs) {
                    // Using size_t, relying on underflow to wrap around to a huge number 
                    // which will safely fail the bounds check (nr < m && nc < n)
                    std::size_t nr = r + d.first;
                    std::size_t nc = c + d.second;

                    if (nr < m && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Mark as rotten
                        fresh_oranges--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes_passed++;
        }

        // Step 3: Check if any fresh oranges survived
        return fresh_oranges == 0 ? minutes_passed : -1;
    }
    
    // ⚠️ STRICT COMPILER REMINDERS (-Wall -Werror):
    // 1. Use std::size_t for looping through container.size()
    // 2. Ensure all code paths return a value
};