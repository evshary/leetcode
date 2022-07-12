class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        for (int c = 2; c <= p.size(); c++) {
        	dp[0][c] = dp[0][c-2] && (p[c-1] == '*');
        }
        for (int r = 1; r <= s.size(); r++) {
        	for (int c = 1; c <= p.size(); c++) {
        		if (p[c-1] == '*') {
                    // There is no case starting with *, so c will always >=2.
        			dp[r][c] = dp[r][c-2] || ((s[r-1] == p[c-2] || p[c-2] == '.') && dp[r-1][c]);
        		} else {
        			dp[r][c] = dp[r-1][c-1] && (s[r-1] == p[c-1] || p[c-1] == '.');
        		}
        	}
        }
        return dp[s.size()][p.size()];
    }
};