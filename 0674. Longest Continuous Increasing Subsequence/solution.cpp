class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
#if 1
        // TC:O(N), SC:O(1)
        int count = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1])
                count++;
            else
                count = 1;
            result = max(result, count);
        }
        return result;
#else
        // TC:O(N), SC:O(N)
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) dp[i] = dp[i-1] + 1;
            result = max(result, dp[i]);
        }
        return result;
#endif
    }
};