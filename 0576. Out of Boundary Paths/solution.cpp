class Solution {
private:
    int traverse(int m, int n, int moves, int r, int c, vector<vector<vector<int>>>& dp) {
        if (r >= m || c >= n || r < 0 || c < 0) return 1;
        if (moves == 0) return 0;
        if (dp[r][c][moves] != -1) return dp[r][c][moves];
        int steps = 0;
        int mod = 1000000007;
        steps = (steps + traverse(m, n, moves-1, r-1, c, dp)) % mod;
        steps = (steps + traverse(m, n, moves-1, r+1, c, dp)) % mod;
        steps = (steps + traverse(m, n, moves-1, r, c-1, dp)) % mod;
        steps = (steps + traverse(m, n, moves-1, r, c+1, dp)) % mod;
        dp[r][c][moves] = steps;
        return steps;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return traverse(m, n, maxMove, startRow, startColumn, dp);
    }
};