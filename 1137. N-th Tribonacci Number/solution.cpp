#if 1
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        vector<int> dp(n+1, 0);
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
};
#else
class Solution {
private:
    unordered_map<int,int> hash;
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        if (hash.count(n)) return hash[n];
        hash[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        return hash[n];
    }
};
#endif