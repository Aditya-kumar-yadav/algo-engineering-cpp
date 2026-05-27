/* * ID: 207
 * Title: Course Schedule
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    bool hasCycle(int node, std::vector<int>& vis, std::vector<int>& pathVis, const std::vector<std::vector<int>>& adj) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (hasCycle(neighbor, vis, pathVis, adj)) {
                    return true;
                }
            } 
            else if (pathVis[neighbor] == 1) {
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        
        for (std::size_t i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        std::vector<int> vis(numCourses, 0);
        std::vector<int> pathVis(numCourses, 0);
        
        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i]) {
                if (hasCycle(i, vis, pathVis, adj)) {
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