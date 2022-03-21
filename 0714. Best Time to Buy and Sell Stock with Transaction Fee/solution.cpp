class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
#if 1 // space O(1)
        int buy = -prices[0] - fee, sell = 0;
        for (int i = 1; i < prices.size(); i++) {
            int tmp_buy = buy;
            buy = max(buy, sell - prices[i] - fee);
            sell = max(sell, tmp_buy + prices[i]);
        }
        return sell;
#else
        vector<int> buy(prices.size()), sell(prices.size());
        buy[0] = -prices[0] - fee;
        sell[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy[i] = max(buy[i-1], sell[i-1] - prices[i] - fee);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        }
        return sell[prices.size()-1];
#endif
    }
};