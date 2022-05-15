#if 1 // space complexity O(1)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[r].size(); c++) {
                if (matrix[r][c] == 0) continue;
                if (r > 0 && c > 0) {
                    matrix[r][c] = 1 + min(matrix[r-1][c-1], min(matrix[r-1][c], matrix[r][c-1]));
                }
                result += matrix[r][c];
            }
        }
        return result;
    }
};
#else
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> dp_r(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> dp_c(matrix.size(), vector<int>(matrix[0].size(), 0));
        int result = 0;
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[r].size(); c++) {
                if (matrix[r][c] == 0) continue;
                dp_r[r][c] = 1 + ((r > 0)?dp_r[r-1][c]:0);
                dp_c[r][c] = 1 + ((c > 0)?dp_c[r][c-1]:0);
                if (r > 0 && c > 0) {
                    dp[r][c] = min(dp[r-1][c-1]+1, min(dp_r[r][c],dp_c[r][c]));
                } else {
                    dp[r][c] = 1;
                }
                result += dp[r][c];
            }
        }
        return result;
    }
};
#endif