class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int max_row = triangle.size();
        vector<int> dp(max_row, 10001);
        vector<int> tmp_dp(max_row, 10001);
        dp[0] = triangle[0][0];
        for (int r = 1; r < max_row; r++) {
            for (int c = 0; c < triangle[r].size(); c++) {
                if (c == 0) {
                    tmp_dp[c] = dp[c] + triangle[r][c];
                } else if (c == triangle[r].size()-1) {
                    tmp_dp[c] = dp[c-1] + triangle[r][c];
                } else {
                    tmp_dp[c] = min(dp[c], dp[c-1]) + triangle[r][c];
                }
            }
            swap(dp, tmp_dp);
        }
        int res = 2000001;
        for (auto v : dp) {
            res = min(v, res);
        }
        return res;
    }
};
