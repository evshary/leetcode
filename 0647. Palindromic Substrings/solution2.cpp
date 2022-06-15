class Solution {
public:
    int countSubstrings(string s) {
        // TC:O(S^2), SC:O(S^2)
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        int count = 0;
        for (int r = s.size()-1; r >= 0; r--) {
            for (int c = s.size()-1; c >= r; c--) {
                if (r+1 <= c-1) {
                    dp[r][c] = dp[r+1][c-1] & (s[r] == s[c]);
                } else {
                    dp[r][c] = (s[r] == s[c]);
                }
                if (dp[r][c]) count++;
            }
        }
        return count;
    }
};