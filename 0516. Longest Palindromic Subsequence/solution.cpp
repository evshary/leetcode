class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int r = s.size()-1; r >= 0; r--) {
            for (int c = r+1; c < s.size(); c++) {
                if (s[r] == s[c]) {
                    if (r+1 <= c-1) {
                        dp[r][c] = dp[r+1][c-1] + 2;
                    } else {
                        dp[r][c] = 2;
                    }
                } else {
                    dp[r][c] = max(dp[r+1][c], dp[r][c-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};