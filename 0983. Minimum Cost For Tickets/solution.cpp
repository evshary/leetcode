#if 1
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int,int>> days7;
        queue<pair<int,int>> days30;
        int cost = 0;
        for (auto d : days) {
            while (!days7.empty() && days7.front().first + 7 <= d) days7.pop();
            while (!days30.empty() && days30.front().first + 30 <= d) days30.pop();
            days7.push({d, cost + costs[1]});
            days30.push({d, cost + costs[2]});
            cost = min({cost + costs[0], days7.front().second, days30.front().second});
        }
        return cost;
    }
};
#else
class Solution {
private:
    int traverse(vector<int>& days, int idx, vector<int>& costs, vector<int>& dp) {
        int total_cost = INT_MAX;
        int jump_days[] = {1, 7, 30};
        if (idx >= days.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        for (int i = 0; i < costs.size(); i++) {
            int new_idx = idx;
            while (new_idx < days.size() && days[new_idx] < days[idx] + jump_days[i]) {
                new_idx++;
            }
            total_cost = min(total_cost, costs[i] + traverse(days, new_idx, costs, dp));
        }
        dp[idx] = total_cost;
        return total_cost;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return traverse(days, 0, costs, dp);
    }
};
#endif