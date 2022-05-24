class Solution {
public:
    long long numberOfWays(string s) {
#if 1
        // dp[i][j]
        // i: len, e.g. len 2 means 01 / 10, len 3 means 010 / 101
        // j: end with 0 / 1
        long long dp[3+1][2] = {0};
        dp[0][0] = dp[0][1] = 1; // This is tricky: since c0 & c1 needs to add 1
        for (auto c : s) {
            int ch = c-'0';
            int reverse_ch = 1 - ch;
            for (int i = 1; i < 4; i++) {
                dp[i][ch] += dp[i-1][reverse_ch];
            }
        }
        return dp[3][0] + dp[3][1];

#else
        long long c0, c1, c01, c10, c010, c101;
        c0 = c1 = c01 = c10 = c010 = c101 = 0;
        for (auto c : s) {
            if (c == '0') {
                c010 += c01;
                c10 += c1;
                c0++;
            } else {
                c101 += c10;
                c01 += c0;
                c1++;
            }
        }
        return c101 + c010;
#endif
    }
};