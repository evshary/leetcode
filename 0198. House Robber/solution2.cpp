class Solution {
public:
    int rob(vector<int>& nums) {
#if 1   // TC: O(N), SC: O(1)
        int dp[2];
        dp[0] = nums[0];
        if (nums.size() <= 1) return dp[0]; 
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int max_rob = max(dp[1], dp[0] + nums[i]);
            dp[0] = dp[1];
            dp[1] = max_rob;
        }
        return dp[1];
#else
        // TC: O(N), SC: O(N)
        vector<int> dp(nums);
        dp[0] = nums[0];
        if (nums.size() > 1) dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];
#endif
    }
};