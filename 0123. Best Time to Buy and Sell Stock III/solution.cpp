class Solution {
public:
    int maxProfit(vector<int>& prices) {
#if 1
        // TC:O(N), SC:O(1)
        vector<int> dp(5);
        dp[0] = dp[2] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[3] = max(dp[3], dp[2]+prices[i]);
            dp[2] = max(dp[2], dp[1]-prices[i]);
            dp[1] = max(dp[1], dp[0]+prices[i]);
            dp[0] = max(dp[0], -prices[i]);
        }
        return dp[3];
#else
        // TC:O(N), SC:O(1)
        // 0 means buy 1st stock
        // 1 means sell 1st stock
        // 2 means buy 2nd stock
        // 3 means sell 2nd stock
        vector<vector<int>> dp(prices.size(), vector<int>(5));
        dp[0][0] = dp[0][2] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]-prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2]+prices[i]);
        }
        return dp[prices.size()-1][3];
#endif
    }
};