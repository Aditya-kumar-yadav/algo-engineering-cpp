/* * ID: 802
 * Title: Find Eventual Safe States
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    // Helper function to perform DFS
    // state: 0 = unvisited, 1 = visiting (in current path), 2 = safe
    bool dfs(int node, const std::vector<std::vector<int>>& graph, std::vector<int>& state) {
        // If we have visited this node before, return true only if it's already marked safe.
        // If it's 1 (visiting), we found a cycle, so it's not safe (returns false).
        if (state[node] != 0) {
            return state[node] == 2;
        }
        
        // Mark the current node as visiting
        state[node] = 1;
        
        // Traverse all adjacent nodes
        for (std::size_t i = 0; i < graph[node].size(); ++i) {
            if (!dfs(graph[node][i], graph, state)) {
                return false; // Found a cycle down this path
            }
        }
        
        // If all paths lead to terminal/safe nodes, mark this node as safe
        state[node] = 2;
        return true;
    }

public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
        std::size_t n = graph.size();
        std::vector<int> state(n, 0); 
        std::vector<int> safeNodes;
        
        for (std::size_t i = 0; i < n; ++i) {
            if (dfs(i, graph, state)) {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
    
    // ⚠️ STRICT COMPILER REMINDERS (-Wall -Werror):
    // 1. Use std::size_t for looping through container.size()
    // 2. Ensure all code paths return a value
};