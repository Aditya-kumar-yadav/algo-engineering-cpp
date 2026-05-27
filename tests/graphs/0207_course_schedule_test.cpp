#include <gtest/gtest.h>
#include "graphs/0207_course_schedule.hpp" // Strictly pathed and lowercased
#include <vector>

TEST(CourseScheduleTest, PossibleToFinish) {
    Solution sol;
    // Example 1: To take 1 you must finish 0. (Valid)
    std::vector<std::vector<int>> prerequisites = {{1, 0}};
    EXPECT_TRUE(sol.canFinish(2, prerequisites));
}

TEST(CourseScheduleTest, ImpossibleDueToCycle) {
    Solution sol;
    // Example 2: 1 requires 0, and 0 requires 1. (Cycle)
    std::vector<std::vector<int>> prerequisites = {{1, 0}, {0, 1}};
    EXPECT_FALSE(sol.canFinish(2, prerequisites));
}

TEST(CourseScheduleTest, ComplexValidDiamondGraph) {
    Solution sol;
    // Cross-edge test: 3 requires 1 and 2, both require 0. (Valid, no cycle)
    std::vector<std::vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    EXPECT_TRUE(sol.canFinish(4, prerequisites));
}

TEST(CourseScheduleTest, DisconnectedComponents) {
    Solution sol;
    // Multiple disconnected valid schedules.
    std::vector<std::vector<int>> prerequisites = {{1, 0}, {3, 2}};
    EXPECT_TRUE(sol.canFinish(4, prerequisites));
}