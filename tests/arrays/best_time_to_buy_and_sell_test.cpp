#include <gtest/gtest.h>
#include <vector>
#include "arrays/0121_best_time_to_buy_and_sell.hpp"

using namespace std;

TEST(BesttimetobuyandsellTest, HandlesStandardCase) {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int expected = 5;
    EXPECT_EQ(sol.maxProfit(prices), expected);
}

TEST(BesttimetobuyandsellTest, HandlesDecreasingPrices) {
    Solution sol;
    vector<int> prices = {7, 6, 4, 3, 1};
    int expected = 0;
    EXPECT_EQ(sol.maxProfit(prices), expected);
}

TEST(BesttimetobuyandsellTest, HandlesIncreasingPrices) {
    Solution sol;
    vector<int> prices = {1, 2, 3, 4, 5};
    int expected = 4;
    EXPECT_EQ(sol.maxProfit(prices), expected);
}

TEST(BesttimetobuyandsellTest, HandlesEmptyArray) {
    Solution sol;
    vector<int> prices = {};
    int expected = 0;
    EXPECT_EQ(sol.maxProfit(prices), expected);
}

TEST(BesttimetobuyandsellTest, HandlesSingleElement) {
    Solution sol;
    vector<int> prices = {5};
    int expected = 0;
    EXPECT_EQ(sol.maxProfit(prices), expected);
}