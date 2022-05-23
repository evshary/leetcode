#if 1 // bottom-up
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[row][column] = 1;
        vector<pair<int,int>> steps{{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
        while (k-- > 0) {
            vector<vector<double>> new_dp(n, vector<double>(n, 0));
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    for (auto & s : steps) {
                        if (r + s.first < 0 || r + s.first >= n || c + s.second < 0 || c + s.second >=n ) continue;
                        new_dp[r + s.first][c + s.second] += 1.0/8.0 * dp[r][c];
                    }
                }
            }
            swap(dp, new_dp);
        }
        double result = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                result += dp[r][c];
            }
        }
        return result;
    }
};
#else // top-down
class Solution {
private:
    double traverse(int n, int moves, int row, int col, vector<vector<vector<double>>>& dp) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;
        if (moves == 0) return 1;
        if (dp[row][col][moves] != -1) return dp[row][col][moves];
        double result = 0;
        result += 1.0/8.0 * traverse(n, moves-1, row + 2, col + 1, dp);
        result += 1.0/8.0 * traverse(n, moves-1, row + 2, col - 1, dp);
        result += 1.0/8.0 * traverse(n, moves-1, row - 2, col + 1, dp);
        result += 1.0/8.0 * traverse(n, moves-1, row - 2, col - 1, dp);
        result += 1.0/8.0 * traverse(n, moves-1, row + 1, col + 2, dp);
        result += 1.0/8.0 * traverse(n, moves-1, row - 1, col + 2, dp);
        result += 1.0/8.0 * traverse(n, moves-1, row + 1, col - 2, dp);
        result += 1.0/8.0 * traverse(n, moves-1, row - 1, col - 2, dp);
        dp[row][col][moves] = result;
        return result;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        return traverse(n, k, row, column, dp);
    }
};
#endif