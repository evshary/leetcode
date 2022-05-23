class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
#if 1 // space complexity O(1)
        long long last_max, last_min;
        last_max = last_min = nums[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; i--) {
            long long new_max, new_min;
            new_max = max({(long long)nums[i], nums[i]-last_min, last_max});
            new_min = min(last_min, nums[i]-last_max);
            last_max = new_max;
            last_min = new_min; 
        }
        return last_max;
#else
        vector<long long> max_dp(nums.size());
        vector<long long> min_dp(nums.size());
        max_dp[nums.size()-1] = min_dp[nums.size()-1] = nums[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; i--) {
            max_dp[i] = max({(long long)nums[i], nums[i]-min_dp[i+1], max_dp[i+1]});
            min_dp[i] = min(min_dp[i+1], nums[i]-max_dp[i+1]);
        }
        return max_dp[0];
#endif
    }
};