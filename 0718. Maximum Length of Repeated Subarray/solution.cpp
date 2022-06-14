class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
#if 1
        // TC:O(NM), SC:O(N)
        vector<int> dp(nums2.size());
        int result = 0;
        for (int i = 0; i < nums2.size(); i++) {
            if (nums1[0] == nums2[i]) {
                dp[i] = 1;
                result = 1;
            }
        }
        for (int i = 1; i < nums1.size(); i++) {
            for (int j = nums2.size()-1; j > 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[j] = dp[j-1] + 1;
                    result = max(result, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
            if (nums1[i] == nums2[0]) {
                dp[0] = 1;
                result = max(result, 1);
            } else {
                dp[0] = 0;
            }
        }
        return result;
#else
        // TC:O(NM), SC:O(NM)
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));
        int result = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
                result = 1;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (nums1[0] == nums2[i]) {
                dp[0][i] = 1;
                result = 1;
            }
        }
        for (int i = 1; i < nums1.size(); i++) {
            for (int j = 1; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result;
#endif
    }
};