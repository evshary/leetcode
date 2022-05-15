#if 1 // bottom-up
class Solution {
public:
    int numRollsToTarget(int num, int face, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int n = 1; n <= num; n++) {
            vector<int> new_dp(target + 1, 0);
            for (int t = n; t <= target; t++) {
                for (int f = 1; f <= face && t >= f; f++) {
                    new_dp[t] = (new_dp[t] + dp[t-f]) % 1000000007;
                }
            }
            swap(dp, new_dp);
        }
        return dp[target];
    }
};
#else // top-down
class Solution {
private:
    int roll(int n, int k, int target, vector<vector<int>>& dp) {
        if (n == 0 && target == 0) return 1;
        if (n == 0 || target <= 0) return 0;
        if (dp[n-1][target-1] == -1) {
            int result = 0;
            for (int i = 1; i <= k; i++) {
                result += roll(n-1, k, target-i, dp);
                result = result % 1000000007;
            }
            dp[n-1][target-1] = result;
        }
        return dp[n-1][target-1];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n, vector<int>(target, -1));
        return roll(n, k, target, dp);
    }
};
#endif