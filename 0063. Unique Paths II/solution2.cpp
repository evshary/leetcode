class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
#if 1 // TC: O(MN) SC: O(N)
        vector<int> dp(obstacleGrid[0].size());
        for (int c = 0; c < obstacleGrid[0].size() && obstacleGrid[0][c] == 0; c++) dp[c] = 1;
        bool no_obstacle_row0 = (obstacleGrid[0][0] == 0);
        for (int r = 1; r < obstacleGrid.size(); r++) {
            vector<int> new_dp(obstacleGrid[r].size());
            if (obstacleGrid[r][0] == 1) no_obstacle_row0 = false;
            if (no_obstacle_row0) new_dp[0] = 1;
            for (int c = 1; c < obstacleGrid[r].size(); c++) {
                if (obstacleGrid[r][c] == 0) {
                    new_dp[c] = dp[c] + new_dp[c-1];
                }
            }
            swap(dp, new_dp);
        }
        return dp[obstacleGrid[0].size()-1];
#else // TC: O(MN) SC: O(MN)
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        for (int r = 0; r < obstacleGrid.size() && obstacleGrid[r][0] == 0; r++) dp[r][0] = 1;
        for (int c = 0; c < obstacleGrid[0].size() && obstacleGrid[0][c] == 0; c++) dp[0][c] = 1;
        for (int r = 1; r < obstacleGrid.size(); r++) {
            for (int c = 1; c < obstacleGrid[r].size(); c++) {
                if (obstacleGrid[r][c] == 0) {
                    dp[r][c] = dp[r-1][c] + dp[r][c-1];
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
#endif
    }
};