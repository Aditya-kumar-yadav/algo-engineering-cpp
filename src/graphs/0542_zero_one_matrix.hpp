/* * ID: 542
 * Title: Zero One Matrix
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};

        // Strictly using std::size_t for container dimensions
        std::size_t m = mat.size();
        std::size_t n = mat[0].size();
        
        std::vector<std::vector<int>> ans(m, std::vector<int>(n, -1));
        std::queue<std::pair<std::size_t, std::size_t>> q;
        
        // Push all 0s into the queue
        for (std::size_t i = 0; i < m; ++i) {
            for (std::size_t j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Multi-Source BFS
        while (!q.empty()) {
            auto p = q.front();
            std::size_t x = p.first;
            std::size_t y = p.second;
            q.pop();
            
            // Down: safe because x + 1 won't overflow practical bounds
            if (x + 1 < m && ans[x + 1][y] == -1) {
                ans[x + 1][y] = ans[x][y] + 1; 
                q.push({x + 1, y});  
            }
            // Up: x > 0 ensures x - 1 will never underflow std::size_t
            if (x > 0 && ans[x - 1][y] == -1) {
                ans[x - 1][y] = ans[x][y] + 1;    
                q.push({x - 1, y});    
            }
            // Right: safe
            if (y + 1 < n && ans[x][y + 1] == -1) {
                ans[x][y + 1] = ans[x][y] + 1;     
                q.push({x, y + 1});    
            }
            // Left: y > 0 ensures y - 1 will never underflow
            if (y > 0 && ans[x][y - 1] == -1) {
                ans[x][y - 1] = ans[x][y] + 1;       
                q.push({x, y - 1});   
            }
        }
        
        return ans;
    }
};