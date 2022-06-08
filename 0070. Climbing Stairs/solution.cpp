class Solution {
public:
    int climbStairs(int n) {
#if 1
        if (n <= 2) return n;
        int dp[2] = {1, 2};
        for (int i = 3; i <= n; i++) {
            int new_ans = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = new_ans;
        }
        return dp[1];
#else // space O(N)
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
#endif
    }
};