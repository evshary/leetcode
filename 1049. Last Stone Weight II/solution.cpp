class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // TC: O(MN), SC(M) while M means the total weight, N means the number
        int sum = 0;
        for (auto s : stones) sum += s;
        int target = sum / 2;
        vector<int> dp(target+1);
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[target];
    }
};