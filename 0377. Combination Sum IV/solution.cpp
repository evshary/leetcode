class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // TC:O(MN), SC:O(M) while M means target, N means nums.size()
        vector<int> dp(target+1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                // The reason why we need dp[i] < INT_MAX-dp[i-nums[j]] is because there are some bad test cases
                if (i - nums[j] >= 0 && dp[i] < INT_MAX-dp[i-nums[j]]) dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};