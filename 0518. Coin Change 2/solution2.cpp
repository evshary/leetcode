class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // TC: O(MN), SC: O(M) while M means amount, N means coin number
        vector<int> dp(amount+1);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};