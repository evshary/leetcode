class Solution {
public:
    int maxProfit(vector<int>& prices) {
#if 1
        // TC:O(N),SC:O(1)
        if (prices.size() == 1) return 0;
        vector<int> dp_buy(2);
        vector<int> dp_sell(2);
        dp_buy[0] = -prices[0];
        dp_buy[1] = max(-prices[0], -prices[1]);
        dp_sell[1] = max(dp_sell[0], dp_buy[0] + prices[1]);
        for (int i = 2; i < prices.size(); i++) {
            int new_buy = max(dp_buy[1], dp_sell[0]-prices[i]);
            int new_sell = max(dp_sell[1], dp_buy[1]+prices[i]);
            dp_buy[0] = dp_buy[1];
            dp_buy[1] = new_buy;
            dp_sell[0] = dp_sell[1];
            dp_sell[1] = new_sell;
        }
        return dp_sell[1];
#else
        // TC:O(N),SC:O(N)
        if (prices.size() == 1) return 0;
        vector<int> dp_buy(prices.size());
        vector<int> dp_sell(prices.size());
        dp_buy[0] = -prices[0];
        dp_buy[1] = max(-prices[0], -prices[1]);
        dp_sell[1] = max(dp_sell[0], dp_buy[0] + prices[1]);
        for (int i = 2; i < prices.size(); i++) {
            dp_buy[i] = max(dp_buy[i-1], dp_sell[i-2]-prices[i]);
            dp_sell[i] = max(dp_sell[i-1], dp_buy[i-1]+prices[i]);
        }
        return dp_sell[prices.size()-1];
#endif
    }
};