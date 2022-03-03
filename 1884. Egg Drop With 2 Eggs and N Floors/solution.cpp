class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(n+1, 1001);
        dp[1] = 1;
        if (n > 1) {
            dp[2] = 2;
            for (int i = 3; i < n+1; i++) {
                for (int j = 1; j < i; j++) {
                    dp[i] = min(dp[i], max(j, dp[i-j]+1));
                }
            }
        }
        return dp[n];
#if 0 // math solution
        int step = 0;
        int sum = 0;
        while (sum < n) {
            step++;
            sum += step;
        }
        return step;
#endif
    }
};