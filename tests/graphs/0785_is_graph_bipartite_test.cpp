#include <gtest/gtest.h>
#include <vector>
#include "graphs/0785_is_graph_bipartite.hpp" // Strictly pathed and lowercased

TEST(IsGraphBipartiteTest, Example1_NonBipartite) {
    Solution sol;
    std::vector<std::vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    EXPECT_FALSE(sol.isBipartite(graph));
}

TEST(IsGraphBipartiteTest, Example2_Bipartite) {
    Solution sol;
    std::vector<std::vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    EXPECT_TRUE(sol.isBipartite(graph));
}

TEST(IsGraphBipartiteTest, DisconnectedBipartite) {
    Solution sol;
    // Two separate valid bipartite components: {0-1} and {2-3}
    std::vector<std::vector<int>> graph = {{1}, {0}, {3}, {2}};
    EXPECT_TRUE(sol.isBipartite(graph));
}

TEST(IsGraphBipartiteTest, DisconnectedNonBipartite) {
    Solution sol;
    // First component {0-1} is valid, second component {2-3-4} forms a triangle (odd cycle = invalid)
    std::vector<std::vector<int>> graph = {{1}, {0}, {3, 4}, {2, 4}, {2, 3}};
    EXPECT_FALSE(sol.isBipartite(graph));
}

TEST(IsGraphBipartiteTest, EmptyGraphEdges) {
    Solution sol;
    // Graph with 4 nodes but 0 edges
    std::vector<std::vector<int>> graph = {{}, {}, {}, {}};
    EXPECT_TRUE(sol.isBipartite(graph));
}