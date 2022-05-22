class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1));
        for (int t1 = 1; t1 <= text1.size(); t1++) {
            for (int t2 = 1; t2 <= text2.size(); t2++) {
                dp[t1][t2] = (text1[t1-1] == text2[t2-1])? dp[t1-1][t2-1] + 1:max(dp[t1-1][t2], dp[t1][t2-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};