class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
#if 1
        // TC:O(MN), SC:O(N) while M is the length of text1, N is the length of text2
        vector<int> dp(text2.size());
        bool one = false;
        for (int i = 0; i < text2.size(); i++) {
            if (one || text1[0] == text2[i]) {
                one = true;
                dp[i] = 1;
            }
        }
        for (int r = 1; r < text1.size(); r++) {
            vector<int> new_dp(text2.size());
            if (dp[0] == 1 || text1[r] == text2[0]) new_dp[0] = 1;
            for (int c = 1; c < text2.size(); c++) {
                new_dp[c] = max(new_dp[c-1], dp[c]);
                if (text1[r] == text2[c]) {
                    new_dp[c] = max(new_dp[c], dp[c-1]+1);
                }
            }
            swap(dp, new_dp);
        }
        return dp[text2.size()-1];
#else
        // TC:O(MN), SC:O(MN)
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size()));
        bool one = false;
        for (int i = 0; i < text1.size(); i++) {
            if (one || text1[i] == text2[0]) {
                one = true;
                dp[i][0] = 1;
            }
        }
        one = false;
        for (int i = 0; i < text2.size(); i++) {
            if (one || text1[0] == text2[i]) {
                one = true;
                dp[0][i] = 1;
            }
        }
        for (int r = 1; r < text1.size(); r++) {
            for (int c = 1; c < text2.size(); c++) {
                dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
                if (text1[r] == text2[c]) {
                    dp[r][c] = max(dp[r][c], dp[r-1][c-1]+1);
                }
            }
        }
        return dp[text1.size()-1][text2.size()-1];
#endif
    }
};