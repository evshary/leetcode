class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // TC: O(N^2), SC: O(N)
        int sum = 0;
        for (auto n : nums) sum += n;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<int> dp(target+1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) return true;
        return false;
    }
};
