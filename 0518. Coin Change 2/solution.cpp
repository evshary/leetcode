class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int c = 0; c < coins.size(); c++) {
            for (int i = 0; i < amount+1; i++) {
                if (i + coins[c] <= amount) {
                    dp[i+coins[c]] += dp[i];
                }
            }
        }
        return dp[amount];
    }
};