#include <gtest/gtest.h>
#include <vector>
#include "graphs/0802_find_eventual_safe_states.hpp" // Strictly pathed and lowercased

TEST(FindEventualSafeStatesTest, Example1) {
    Solution sol;
    std::vector<std::vector<int>> graph = {
        {1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}
    };
    std::vector<int> expected = {2, 4, 5, 6};
    EXPECT_EQ(sol.eventualSafeNodes(graph), expected);
}

TEST(FindEventualSafeStatesTest, Example2) {
    Solution sol;
    std::vector<std::vector<int>> graph = {
        {1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}
    };
    std::vector<int> expected = {0};
    EXPECT_EQ(sol.eventualSafeNodes(graph), expected);
}

TEST(FindEventualSafeStatesTest, AllTerminalNodes) {
    Solution sol;
    // Graph where no nodes have outgoing edges
    std::vector<std::vector<int>> graph = {
        {}, {}, {}
    };
    std::vector<int> expected = {0, 1, 2};
    EXPECT_EQ(sol.eventualSafeNodes(graph), expected);
}

TEST(FindEventualSafeStatesTest, CompleteCycle) {
    Solution sol;
    // Graph where 0->1, 1->2, 2->0 (all part of a cycle)
    std::vector<std::vector<int>> graph = {
        {1}, {2}, {0}
    };
    std::vector<int> expected = {}; // No safe nodes
    EXPECT_EQ(sol.eventualSafeNodes(graph), expected);
}

TEST(FindEventualSafeStatesTest, SelfLoop) {
    Solution sol;
    // Node 0 has a self-loop, node 1 is terminal
    std::vector<std::vector<int>> graph = {
        {0, 1}, {}
    };
    std::vector<int> expected = {1}; 
    EXPECT_EQ(sol.eventualSafeNodes(graph), expected);
}