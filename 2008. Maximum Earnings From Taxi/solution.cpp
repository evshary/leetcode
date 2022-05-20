#if 1
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        unordered_map<int, vector<pair<int, int>>> hash;
        for (auto &r : rides) {
            hash[r[1]].push_back({r[0], r[1] - r[0] + r[2]});
        }
        vector<long long> dp(n+1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            if (hash.count(i)) {
                for (auto& v : hash[i]) {
                    dp[i] = max(dp[i], dp[v.first] + v.second);
                }
            }
        }
        return dp[n];
    }
};
#else  // TLE
class Solution {
private:
    int traverse(unordered_map<int, vector<pair<int, int>>>& hash, int index, int max_idx, unordered_map<int, int>& dp) {
        int income = 0;
        if (dp.count(index)) return dp[index];
        for (int i = index; i <= max_idx; i++) {
            if (hash.count(i)) {
                for (auto& v : hash[i]) {
                    income = max(income, traverse(hash, v.first, max_idx, dp) + v.second);
                }
            }
        }
        dp[index] = income;
        return income;
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        unordered_map<int, vector<pair<int, int>>> hash;
        unordered_map<int, int> dp;
        for (auto &r : rides) {
            hash[r[0]].push_back({r[1], r[1] - r[0] + r[2]});
        }
        return traverse(hash, 1, n, dp);
    }
};
#endif