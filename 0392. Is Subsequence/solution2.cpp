class Solution {
public:
    bool isSubsequence(string s, string t) {
#if 1
        // Two pointers
        int sp = 0, tp = 0;
        while (sp != s.size() && tp != t.size()) {
            if (t[tp] == s[sp]) {
                tp++;
                sp++;
            } else {
                tp++;
            }
        }
        return sp == s.size();
#else
        // DP solution: TC:O(ST), SC:O(ST) 
        if (s.size() == 0) return true;
        if (t.size() == 0) return false;
        vector<vector<bool>> dp(s.size(), vector<bool>(t.size()));
        dp[0][0] = s[0] == t[0];
        for (int i = 1; i < t.size(); i++) {
            dp[0][i] = dp[0][i-1] | (s[0] == t[i]);
        }
        for (int r = 1; r < s.size(); r++) {
            dp[r][0] = false;
            for (int c = 1; c < t.size(); c++) {
                if (s[r] == t[c] && dp[r-1][c-1]) {
                    dp[r][c] = true;
                } else {
                    dp[r][c] = dp[r][c-1];
                }
            }
        }
        return dp[s.size()-1][t.size()-1];
#endif
    }
};