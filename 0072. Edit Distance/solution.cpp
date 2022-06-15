class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        for (int r = 1; r <= word1.size(); r++) {
            dp[r][0] = dp[r-1][0] + 1;
        }
        for (int c = 1; c <= word2.size(); c++) {
            dp[0][c] = dp[0][c-1] + 1;
        }
        for (int r = 1; r <= word1.size(); r++) {
            for (int c = 1; c <= word2.size(); c++) {
                if (word1[r-1] == word2[c-1]) {
                    dp[r][c] = dp[r-1][c-1];
                } else {
                    dp[r][c] = min({dp[r-1][c], dp[r][c-1], dp[r-1][c-1]}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};