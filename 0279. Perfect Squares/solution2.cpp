class Solution {
public:
    int numSquares(int n) {
        // TC: O(N^2), SC: O(N)
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                dp[j] = min(dp[j], dp[j-i*i]+1);
            }
        }
        return dp[n];
    }
};