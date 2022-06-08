class Solution {
public:
    int uniquePaths(int m, int n) {
#if 1    // TC: O(min(M,N)) SC: O(1)
        long long numerator = 1;
        long long denominator = 1;
        int total = m + n - 2;
        int count = min(m - 1, n-1);
        while (count != 0) {
            numerator *= total;
            total--;
            denominator *= count;
            count--;
            if (numerator % denominator == 0) {
                numerator /= denominator;
                denominator = 1;
            }
        }
        return numerator / denominator;
#elif 1  // TC: O(MN)  SC: O(M)
        vector<int> dp(n, 1);
        for (int r = 1; r < m; r++) {
            vector<int> new_dp(n);
            new_dp[0] = 1;
            for (int c = 1; c < n; c++) {
                new_dp[c] = dp[c] + new_dp[c-1];
            }
            swap(dp, new_dp);
        }
        return dp[n-1];
#else  // TC: O(MN) SC: O(MN)
        vector<vector<int>> dp(m, vector<int>(n));
        for (int r = 0; r < m; r++) dp[r][0] = 1;
        for (int c = 0; c < n; c++) dp[0][c] = 1;
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                dp[r][c] = dp[r-1][c] + dp[r][c-1];
            }
        }
        return dp[m-1][n-1];
#endif
    }
};