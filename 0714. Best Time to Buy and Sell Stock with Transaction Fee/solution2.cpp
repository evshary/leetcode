class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
#if 1
        // TC:O(N),SC:O(1)
        int dp_buy = -prices[0];
        int dp_sell = 0;
        for (int i = 1; i < prices.size(); i++) {
            int new_dp_buy = max(dp_buy, dp_sell-prices[i]);
            int new_dp_sell = max(dp_sell, dp_buy+prices[i]-fee);
            dp_buy = new_dp_buy;
            dp_sell = new_dp_sell;
        }
        return dp_sell;
#else
        // TC:O(N),SC:O(N)
        vector<int> dp_buy(prices.size());
        vector<int> dp_sell(prices.size());
        dp_buy[0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp_buy[i] = max(dp_buy[i-1], dp_sell[i-1]-prices[i]);
            dp_sell[i] = max(dp_sell[i-1], dp_buy[i-1]+prices[i]-fee);
        }
        return dp_sell[prices.size()-1];
#endif
    }
};