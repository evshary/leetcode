class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
#if 1 // SC: O(1)
        int dp[2] = {cost[0], cost[1]};
        for (int i = 2; i < cost.size(); i++) {
            int new_ans = cost[i] + min(dp[0], dp[1]);
            dp[0] = dp[1];
            dp[1] = new_ans;
        }
        return min(dp[0], dp[1]);
#else // SC: O(N)
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[cost.size()-1], dp[cost.size()-2]);
#endif
    }
};
