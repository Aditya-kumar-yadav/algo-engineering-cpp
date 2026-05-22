#include <gtest/gtest.h>
// Correctly pathed for your enterprise CMake setup
#include "arrays/0026_remove_duplicates_from_sorted_array.hpp" 

TEST(RemoveDuplicatesTest, StandardCase) {
    Solution sol;
    std::vector<int> nums = {1, 1, 2};
    int len = sol.removeDuplicates(nums);
    
    EXPECT_EQ(len, 2);
    
    std::vector<int> expected = {1, 2};
    for (int i = 0; i < len; ++i) {
        EXPECT_EQ(nums[i], expected[i]);
    }
}

TEST(RemoveDuplicatesTest, MultipleDuplicates) {
    Solution sol;
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int len = sol.removeDuplicates(nums);
    
    EXPECT_EQ(len, 5);
    
    std::vector<int> expected = {0, 1, 2, 3, 4};
    for (int i = 0; i < len; ++i) {
        EXPECT_EQ(nums[i], expected[i]);
    }
}

TEST(RemoveDuplicatesTest, EmptyArray) {
    Solution sol;
    std::vector<int> nums = {};
    EXPECT_EQ(sol.removeDuplicates(nums), 0);
}

TEST(RemoveDuplicatesTest, NoDuplicates) {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int len = sol.removeDuplicates(nums);
    
    EXPECT_EQ(len, 5);
}