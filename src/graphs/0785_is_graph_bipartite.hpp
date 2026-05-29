/* * ID: 785
 * Title: Is Graph Bipartite?
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>

class Solution {
private:
    // Helper function to perform DFS graph coloring
    // colors: 0 = uncolored, 1 = Color A, -1 = Color B
    bool dfs(int node, int current_color, const std::vector<std::vector<int>>& graph, std::vector<int>& colors) {
        colors[node] = current_color;
        
        for (std::size_t i = 0; i < graph[node].size(); ++i) {
            int neighbor = graph[node][i];
            
            // If the neighbor has the exact same color, it's not bipartite
            if (colors[neighbor] == current_color) {
                return false;
            }
            
            // If the neighbor is uncolored, recursively color it with the opposite color
            if (colors[neighbor] == 0) {
                if (!dfs(neighbor, -current_color, graph, colors)) {
                    return false;
                }
            }
        }
        
        return true;
    }

public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
        int n = graph.size();
        std::vector<int> colors(n, 0);
        
        // The graph might be disconnected, so we check every node
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 0) {
                // Start coloring this component with color '1'
                if (!dfs(i, 1, graph, colors)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    // ⚠️ STRICT COMPILER REMINDERS (-Wall -Werror):
    // 1. Use std::size_t for looping through container.size()
    // 2. Ensure all code paths return a value
};