class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<vector<int>>> roads(connections.size()+1);
        vector<bool> visited(connections.size()+1, false);
        for (auto & c : connections) {
            roads[c[0]].push_back(c);
            roads[c[1]].push_back(c);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int swap_num = 0;
        while (!q.empty()) {
            int cur_city = q.front();
            q.pop();
            for (auto & r : roads[cur_city]) {
                int neighbor = (r[0] == cur_city)? r[1]:r[0];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    if (r[0] == cur_city)
                        swap_num++;
                    q.push(neighbor);
                }
            }
        }
        return swap_num;
    }
};
