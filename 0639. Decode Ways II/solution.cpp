class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size());
        for (int i = s.size()-1; i >= 0; i--) {
            int sum = 0;
            if (s[i] == '*') {
                sum = 9;
            } else if (s[i] != '0'){
                sum = 1;
            }
            if (i + 1 < s.size()) {
                for (int j = 0; j < sum; j++) {
                    dp[i] = (dp[i] + dp[i+1]) % 1000000007;
                }
            } else {
                dp[i] = sum;
            }
            if (i + 1 < s.size()) {
                sum = 0;
                if (s[i] == '*' && s[i+1] == '*') {
                    sum = 15;
                } else if (s[i] == '*' && s[i+1] != '*') {
                    if (s[i+1] <= '6') {
                        sum = 2;
                    } else {
                        sum = 1;
                    }
                } else if (s[i] != '*' && s[i+1] == '*') {
                    if (s[i] == '1') {
                        sum = 9;
                    } else if (s[i] == '2') {
                        sum = 6;
                    }
                } else {
                    if ((s[i] == '1') ||
                        (s[i] == '2' && s[i+1] <= '6')) {
                        sum = 1;
                    }
                }
                if (i + 2 < s.size()) {
                    for (int j = 0; j < sum; j++) {
                        dp[i] = (dp[i] + dp[i+2]) % 1000000007;
                    }
                } else {
                    dp[i] += sum;
                }
            }
        }
        return dp[0];
    }
};