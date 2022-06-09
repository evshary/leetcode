class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // TC: O(SMN), SC: O(MN)
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (auto & s : strs) {
            int zeroNum = 0, oneNum = 0;
            for (auto c : s) {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            for (int i = m; i >= zeroNum; i--) {
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i-zeroNum][j-oneNum]+1);
                }
            }
        }
        return dp[m][n];
    }
};