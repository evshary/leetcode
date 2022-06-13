class Solution {
public:
    int maxProfit(vector<int>& prices) {
#if 1  // TC: O(N), SC: O(1)
        int dp_w_stock = -prices[0];
        int dp_wo_stock = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp_wo_stock = max(dp_wo_stock, dp_w_stock+prices[i]);
            dp_w_stock = max(dp_w_stock, -prices[i]);
        }
        return dp_wo_stock;
#else  // TC: O(N), SC: O(N)
        vector<int> dp_w_stock(prices.size());
        vector<int> dp_wo_stock(prices.size());
        dp_w_stock[0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp_w_stock[i] = max(dp_w_stock[i-1], -prices[i]);
            dp_wo_stock[i] = max(dp_wo_stock[i-1], dp_w_stock[i-1]+prices[i]);
        }
        return dp_wo_stock[prices.size()-1];
#endif
    }
};