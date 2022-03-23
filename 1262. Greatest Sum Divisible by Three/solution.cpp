class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp{0, INT_MIN, INT_MIN};
        for (auto n : nums) {
            vector<int> tmp_dp(dp);
            if (n % 3 == 0) {
                tmp_dp[0] = max(dp[0], dp[0]+n);
                tmp_dp[1] = max(dp[1], dp[1]+n);
                tmp_dp[2] = max(dp[2], dp[2]+n);
            } else if (n % 3 == 1) {
                tmp_dp[0] = max(dp[0], dp[2]+n);
                tmp_dp[1] = max(dp[1], dp[0]+n);
                tmp_dp[2] = max(dp[2], dp[1]+n);
            } else if (n % 3 == 2) {
                tmp_dp[0] = max(dp[0], dp[1]+n);
                tmp_dp[1] = max(dp[1], dp[2]+n);
                tmp_dp[2] = max(dp[2], dp[0]+n);
            }
            swap(tmp_dp, dp);
        }
        return dp[0];
    }
};