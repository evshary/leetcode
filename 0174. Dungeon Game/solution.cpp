class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rmax = dungeon.size();
        int cmax = dungeon[0].size();
        vector<vector<int>> dp(rmax+1, vector<int>(cmax+1, INT_MAX));
        dp[rmax-1][cmax] = dp[rmax][cmax-1] = 1;
        for (int r = rmax-1; r >= 0; r--) {
            for (int c = cmax-1; c >= 0; c--) {
                dp[r][c] = max(1, min(dp[r+1][c], dp[r][c+1]) - dungeon[r][c]);
            }
        }
        return dp[0][0];
    }
};