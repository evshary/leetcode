#if 1
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(1001));
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500;
                if (dp[j][diff] != 0) {
                    dp[i][diff] = dp[j][diff] + 1;
                } else {
                    dp[i][diff] = 2;
                }
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};
#else  // TLE
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int,int>> hash(nums.size());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i]-nums[j];
                if (hash[j].count(diff)) {
                    hash[i][diff] = hash[j][diff] + 1;
                } else {
                    hash[i][diff] = 2;
                }
                ans = max(ans, hash[i][diff]);
            }
        }
        return ans;
    }
};
#endif