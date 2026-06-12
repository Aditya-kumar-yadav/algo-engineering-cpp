#include <gtest/gtest.h>
#include <vector>
#include "graphs/1319_number_of_operations_to_make_network_connected.hpp" // Strictly pathed and lowercased

TEST(NumberofOperationstoMakeNetworkConnectedTest, Example1) {
    Solution sol;
    int n = 4;
    std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    EXPECT_EQ(sol.makeConnected(n, connections), 1);
}

TEST(NumberofOperationstoMakeNetworkConnectedTest, Example2) {
    Solution sol;
    int n = 6;
    std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    EXPECT_EQ(sol.makeConnected(n, connections), 2);
}

TEST(NumberofOperationstoMakeNetworkConnectedTest, Example3) {
    Solution sol;
    int n = 6;
    std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
    EXPECT_EQ(sol.makeConnected(n, connections), -1);
}

TEST(NumberofOperationstoMakeNetworkConnectedTest, DisconnectedComponents) {
    Solution sol;
    int n = 5;
    std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {3, 4}, {2, 3}};
    EXPECT_EQ(sol.makeConnected(n, connections), 0);
}