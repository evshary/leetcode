class Solution {
public:
    int minDistance(string word1, string word2) {
        // TC:O(MN), SC:O(MN)
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        for (int r = 1; r <= word1.size(); r++) {
            for (int c = 1; c <= word2.size(); c++) {
                dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
                if (word1[r-1] == word2[c-1]) {
                    dp[r][c] = max(dp[r][c], dp[r-1][c-1]+1);
                }
            }
        }
        return word1.size() + word2.size() - (2 * dp[word1.size()][word2.size()]);
    }
};