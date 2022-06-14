class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // TC:O(MN), SC:O(N)
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1));
        for (int r = 1; r <= nums1.size(); r++) {
            for (int c = 1; c <= nums2.size(); c++) {
                dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
                if (nums1[r-1] == nums2[c-1]) {
                    dp[r][c] = max(dp[r][c], dp[r-1][c-1]+1);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};