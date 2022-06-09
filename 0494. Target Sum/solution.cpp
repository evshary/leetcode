class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // TC: O(NM), SC: O(M), while N means nums.size(), M means sum of nums
        // left + right = sum
        // left - right = target
        // left = (sum + target) / 2
        int sum = 0;
        for (auto n : nums) sum += n;
        if ((sum + target) % 2 != 0) return 0;
        if (sum < abs(target)) return 0;
        int left = (sum + target) / 2;
        vector<int> dp(left + 1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = left; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[left];
    }
};