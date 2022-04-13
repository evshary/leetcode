#if 1  // more clear solution
class Solution {
    int rob_range(int begin, int end, vector<int>& nums) {
        int include = nums[begin], exclude = 0;
        for (int i = begin+1; i <= end; i++) {
            int new_include = exclude + nums[i];
            int new_exclude = max(include, exclude);
            include = new_include;
            exclude = new_exclude;
        }
        return max(include, exclude);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(rob_range(0, nums.size()-2, nums), rob_range(1, nums.size()-1, nums));
    }
};
#else
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        /*
         *  0: with end   (current)
         *  1: with end   (no current)
         *  2: with first (current)
         *  3: with first (no current)
         */
        vector<vector<int>> dp(nums.size(), vector<int>(4, 0));
        dp[nums.size()-1] = {nums[nums.size()-1], 0, 0, 0};
        for (int i = nums.size()-2; i >= 1; i--) {
            dp[i][0] = dp[i+1][1] + nums[i];
            dp[i][1] = max(dp[i+1][0], dp[i+1][1]);
            dp[i][2] = dp[i+1][3] + nums[i];
            dp[i][3] = max(dp[i+1][2], dp[i+1][3]);
        }
        dp[0][2] = dp[1][3] + nums[0];
        dp[0][3] = max(dp[1][2], dp[1][3]);
        return max(max(dp[1][0],dp[1][1]), max(dp[0][2],dp[0][3]));
    }
};
#endif