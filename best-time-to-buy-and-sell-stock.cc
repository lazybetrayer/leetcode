// https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;

        int min_price = prices[0]; // 记录之前的最小值
        int max_profit = 0;

        for (vector<int>::size_type i = 1; i < prices.size(); i++) {
            max_profit = max(max_profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }

        return max_profit;
    }
};
