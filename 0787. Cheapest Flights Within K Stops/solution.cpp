class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int final_dst, int k) {
        vector<vector<pair<int,int>>> flight_table(n);
        for (auto & f : flights) {
            flight_table[f[0]].push_back({f[1], f[2]}); // {dst, price}
        }
        vector<bool> visited(n, false);
        queue<vector<int>> q;
        q.push({src, 0, 0});  // {src, step, cost}
        vector<int> cheapest_price(n, 1000001);
        while (!q.empty()) {
            auto state = q.front();
            q.pop();
            for (auto & [dst, price] : flight_table[state[0]]) {
                if (state[1] <= k && cheapest_price[dst] > state[2]+price) {
                    q.push({dst, state[1]+1, state[2]+price});
                    cheapest_price[dst] = state[2]+price;
                }
            }
        }
        return (cheapest_price[final_dst] == 1000001)? -1:cheapest_price[final_dst];
    }
};
