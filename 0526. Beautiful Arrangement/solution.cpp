#if 1
class Solution {
    int traverse(int bitmask, int N, int n, unordered_map<int,int>& dp){
        if (n == 0) return 1;
        if (dp.count(bitmask)) return dp[bitmask];
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if ( !(bitmask & (1 << i)) && 
                 ( ((i+1) % n == 0) || (n % (i+1) == 0) ) 
               ) {
                ans += traverse(bitmask | (1 << i), N, n-1, dp);
            }
        }
        dp[bitmask] = ans;
        return ans;
    }
public:
    int countArrangement(int n) {
        unordered_map<int,int> dp;
        return traverse(0, n, n, dp);
    }
};
#else  // TLE
class Solution {
public:
    int countArrangement(int n) {
        int ans = 0;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }
        do {
            bool passed = true;
            for (int i = 0; i < n; i++) {
                if (v[i] % (i+1) != 0 && (i+1) % v[i] != 0) {
                    passed = false;
                    break;
                }
            }
            if (passed) ans++;
        } while (next_permutation(v.begin(), v.end()));
        return ans;
    }
};
#endif