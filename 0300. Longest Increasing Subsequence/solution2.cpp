class Solution {
public:
#if 1 // O(NlogN)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for (int i = 0; i < nums.size(); i++) {
            if (seq.empty() || seq[seq.size()-1] < nums[i]) {
                seq.push_back(nums[i]);
            } else {
                auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
                *it = nums[i];
            }
        }
        return seq.size();
    }
#else // O(N^2)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
#endif
};