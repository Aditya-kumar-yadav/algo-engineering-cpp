/* * ID: 210
 * Title: Course Schedule II
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> inDegree(numCourses, 0);
        
        // Build the adjacency list and count in-degrees (prerequisites)
        for (std::size_t i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        
        // Push all courses with 0 prerequisites into the queue
        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        std::vector<int> topoOrder;
        
        // Process the graph using BFS
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            topoOrder.push_back(curr);
            
            // "Take" the current course and reduce the prerequisite count for its neighbors
            for (std::size_t i = 0; i < adj[curr].size(); ++i) {
                int nextCourse = adj[curr][i];
                inDegree[nextCourse]--;
                
                // If the neighbor now has 0 prerequisites, it's ready to be taken
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // If we were able to take all courses, return the order. 
        // Otherwise, there was a cycle, so return an empty array.
        if (topoOrder.size() == static_cast<std::size_t>(numCourses)) {
            return topoOrder;
        }
        
        return {};
    }
    
    // ⚠️ STRICT COMPILER REMINDERS (-Wall -Werror):
    // 1. Use std::size_t for looping through container.size()
    // 2. Ensure all code paths return a value
};