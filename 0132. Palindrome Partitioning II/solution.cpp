class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0) return 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        vector<int> minNum(s.size());
        for (int i = 0; i < s.size(); i++) minNum[i] = i;
        for (int end = 0; end < s.size(); end++) {
            for (int begin = end; begin >= 0; begin--) {
                if (s[begin] == s[end] && (end - begin < 2 || dp[begin+1][end-1])) {
                    dp[begin][end] = true;
                    if (begin >= 1) {
                        minNum[end] = min(minNum[end], minNum[begin-1] + 1); 
                    } else {
                        minNum[end] = 0;
                    }
                }
            }
        }
        return minNum[s.size()-1];
    }
};