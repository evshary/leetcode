class Solution {
public:
    int integerBreak(int n) {
        // TC: O(N^2), SC: O(N)
        vector<int> dp(n+1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i-1; j++) {
                dp[i] = max(dp[i], max(j * (i-j), j * dp[i-j]));
            }
        }
        return dp[n];
    }
};