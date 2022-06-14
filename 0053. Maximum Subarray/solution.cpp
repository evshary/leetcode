class Solution {
public:
    int maxSubArray(vector<int>& nums) {
#if 1
        // TC:O(N), SC:O(1)
        int dp = nums[0];
        int result = dp;
        for (int i = 1; i < nums.size(); i++) {
            dp = max(dp+nums[i], nums[i]);
            result = max(result, dp);
        }
        return result;
#else
        // TC:O(N), SC:O(N)
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
#endif
    }
};