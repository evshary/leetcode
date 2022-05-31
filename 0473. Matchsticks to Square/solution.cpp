class Solution {
private:
    bool dfs(vector<int>& matchsticks, int remain_num, int bitmask, int edge_size, int cur_size, unordered_map<int,bool>& dp) {
        if (remain_num == 0) return true;
        bool result = false;
        if (dp.count(bitmask)) return dp[bitmask];
        for (int i = 0; i < matchsticks.size(); i++) {
            if (!(bitmask & (1 << i)) && cur_size + matchsticks[i] <= edge_size) {
                result = dfs(matchsticks, remain_num-1, bitmask | (1 << i), edge_size, (cur_size + matchsticks[i]) % edge_size, dp);
                if (result) break;
            }
        }
        dp[bitmask] = result;
        return result;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int total_size = 0;
        for (auto m : matchsticks) total_size += m;
        if ((total_size % 4) != 0) return false; 
        int edge_size = total_size / 4;
        unordered_map<int,bool> dp;
        return dfs(matchsticks, matchsticks.size(), 0, edge_size, 0, dp);
    }
};