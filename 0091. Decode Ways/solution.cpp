#if 1
class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        vector<int> dp(len);
        for (int i = len-1; i >= 0; i--) {
            if (s[i] != '0') {
                dp[i] += (i+1 < len)? dp[i+1]:1;
            }
            if (i+1 < len) {
                if ((s[i] == '1') || (s[i] == '2' && s[i+1] <= '6')) {
                    dp[i] += (i+2 < len)? dp[i+2]:1;
                }
            }
        }
        return dp[0];
    }
};
#else
class Solution {
private:
    int traverse(string& s, int idx, vector<int>& dp) {
        if (s[idx] == '0') return 0;
        if (idx == s.size()) return 1;
        if (dp[idx] != -1) return dp[idx];
        int ans = traverse(s, idx+1, dp);
        if (idx+1 < s.size()) {
            if (s[idx] == '1') {
                ans += traverse(s, idx+2, dp);
            } else if (s[idx] == '2' && s[idx+1] <= '6') {
                ans += traverse(s, idx+2, dp);
            }
        }
        dp[idx] = ans;
        return ans;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return traverse(s, 0, dp);
    }
};
#endif