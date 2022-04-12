class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
#if 1  // space complexity O(n)
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<long> dp(n, 0);
        for (int r = m-1; r >= 0; r--) {
            vector<long> tmp_dp(n, 0);
            for (int c = n-1; c >= 0; c--) {
                if (obstacleGrid[r][c] == 0) {
                    if (r == m-1 && c == n-1) {
                        tmp_dp[c] = 1;
                    } else {
                        tmp_dp[c] = ((r + 1 < m)?dp[c]:0) + ((c + 1 < n)?tmp_dp[c+1]:0);
                    }
                }
            }
            swap(dp, tmp_dp);
        }
        return dp[0];
#else
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, 0));
        for (int r = m-1; r >= 0; r--) {
            for (int c = n-1; c >= 0; c--) {
                if (obstacleGrid[r][c] == 0) {
                    if (r == m-1 && c == n-1) {
                        dp[r][c] = 1;
                    } else {
                        dp[r][c] = ((r + 1 < m)?dp[r+1][c]:0) + ((c + 1 < n)?dp[r][c+1]:0);
                    }
                }
            }
        }
        return dp[0][0];
#endif
    }
};
