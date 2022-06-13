class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
#if 1
        // TC:O(KN), SC:O(K) while N means #prices
        if (prices.size() == 0) return 0;
        vector<int> dp(2*k+1);
        for (int i = 0; i < k; i++) {
            dp[2*i+1] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 2 * k; j > 0; j--) {
                if (j % 2 == 0) {
                    dp[j] = max(dp[j], dp[j-1] + prices[i]);
                } else {
                    dp[j] = max(dp[j], dp[j-1] - prices[i]);
                }
            }
        }
        return dp[2*k];
#else
        // TC:O(KN), SC:O(KN) while N means #prices
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2*k+1));
        for (int i = 0; i < k; i++) {
            dp[0][2*i+1] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j < 2 * k + 1; j++) {
                if (j % 2 == 0) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]);
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);
                }
            }
        }
        return dp[prices.size()-1][2*k];
#endif
    }
};