class Solution {
public:
    int numDistinct(string s, string t) {
        // TC:O(ST), SC:O(ST)
        vector<vector<uint64_t>> dp(t.size()+1, vector<uint64_t>(s.size()+1));
        for (int c = 0; c <= s.size(); c++) dp[0][c] = 1;
        for (int r = 1; r <= t.size(); r++) {
            for (int c = 1; c <= s.size(); c++) {
                dp[r][c] = dp[r][c-1];
                if (t[r-1] == s[c-1]) {
                    dp[r][c] += dp[r-1][c-1];
                }
            }
        }
        return dp[t.size()][s.size()];
    }
};