/* * ID: 1319
 * Title: Number of Operations to Make Network Connected
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

// Efficient I/O boilerplate
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    std::vector<int> parent;
    std::vector<int> rank;

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]); // Path compression
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
        }
    }

public:
    int makeConnected(int n, std::vector<std::vector<int>>& connections) {
        // To connect n computers, we need at least n - 1 cables
        if (connections.size() < static_cast<std::size_t>(n - 1)) {
            return -1;
        }

        parent.resize(n);
        rank.assign(n, 0);
        std::iota(parent.begin(), parent.end(), 0);

        int components = n;

        // Strict compiler reminder: std::size_t for looping
        for (std::size_t i = 0; i < connections.size(); ++i) {
            int u = connections[i][0];
            int v = connections[i][1];
            
            if (find(u) != find(v)) {
                unite(u, v);
                components--; // Two components merged
            }
        }

        // All paths return a value
        return components - 1; 
    }
};