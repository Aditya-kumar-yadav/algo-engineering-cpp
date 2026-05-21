#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
// This function calculates the maximum profit that can be obtained from buying and selling a stock
    int maxProfit(vector<int>& prices) {
        int min_price = 1e9; // Initialize min_price to a very large number
        int max_profit = 0;
        for(int price : prices) {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        return max_profit;
    }
};

int main() {
    string line;
    Solution sol;
    // Reads each line from tests.txt as a separate test case
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        vector<int> prices;
        int p;
        while (ss >> p) {
            prices.push_back(p);
        }
        cout << sol.maxProfit(prices) << "\n";
    }
    return 0;
}