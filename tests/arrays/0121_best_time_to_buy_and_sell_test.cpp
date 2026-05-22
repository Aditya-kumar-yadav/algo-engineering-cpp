#include <gtest/gtest.h>
// Make sure this include exactly matches your .hpp filename!
#include "arrays/0121_best_time_to_buy_and_sell_stock.hpp" 

TEST(MaxProfitTest, ProfitPossible) {
    Solution sol;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(sol.maxProfit(prices), 5);
}

TEST(MaxProfitTest, NoProfitPossible) {
    Solution sol;
    std::vector<int> prices = {7, 6, 4, 3, 1};
    EXPECT_EQ(sol.maxProfit(prices), 0);
}

TEST(MaxProfitTest, EmptyArray) {
    Solution sol;
    std::vector<int> prices = {};
    EXPECT_EQ(sol.maxProfit(prices), 0);
}