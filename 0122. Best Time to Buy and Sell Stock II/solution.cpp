class Solution {
public:
    int maxProfit(vector<int>& prices) {
#if 1
        int buy = -prices[0], sell = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy = max(buy, sell-prices[i]);
            sell = max(sell, buy+prices[i]);
        }
        return sell;
#else // another solution
        int low = prices[0], high = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (high > prices[i]) {
                profit += high - low;
                high = low = prices[i];
            } else {
                high = prices[i];
            }
        }
        profit += high - low; // the last one
        return profit;
#endif
    }
};