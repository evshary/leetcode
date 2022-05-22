class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size()));
        for (int r = 0; r < word1.size(); r++) {
            for (int c = 0; c < word2.size(); c++) {
                int left = (c > 0)? dp[r][c-1] : 0;
                int up = (r > 0)? dp[r-1][c] : 0;
                int last = (r > 0 && c > 0)? dp[r-1][c-1] : 0;
                dp[r][c] = (word1[r] == word2[c])? last + 1 : max(left, up);
            }
        }
        return word1.size() + word2.size() - dp[word1.size()-1][word2.size()-1] * 2;
    }
};