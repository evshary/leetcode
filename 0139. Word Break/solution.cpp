class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // TC: O(N^3), SC: O(N)
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        unordered_map<string, bool> hash;
        for (auto w : wordDict) hash[w] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = hash.count(s.substr(j, i-j)) & dp[j];
                if (dp[i]) break;
            }
        }
        return dp[s.size()];
    }
};