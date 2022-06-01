class Solution {
private:
    int dfs(vector<vector<int>>& distances, int cur_node, int bitmask, int remain_node, int cur_path, unordered_map<int,int>& dp) {
        if (remain_node == 0) {
            return cur_path;
        }
        if (dp.count((cur_node << 12) + bitmask)) return dp[(cur_node << 12) + bitmask] + cur_path;
        int shortest_path = INT_MAX;
        for (int i = 0; i < distances.size(); i++) {
            if (!(bitmask & (1 << i))) {
                int path = dfs(distances, i, bitmask | (1 << i), remain_node - 1, cur_path + distances[cur_node][i], dp);
                shortest_path = min(shortest_path, path);
            }
        }
        dp[(cur_node << 12) + bitmask] = shortest_path - cur_path;
        return shortest_path;
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int node_num = graph.size();
        vector<vector<int>> distances(node_num, vector<int>(node_num, 0));
        // Build distance map: the smallest distance from i to j
        for (int i = 0; i < node_num; i++) {
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (auto next_node : graph[node]) {
                    if (i != next_node && distances[i][next_node] == 0) {
                        distances[i][next_node] = distances[i][node] + 1;
                        q.push(next_node);
                    }
                }
            }
        }
        // Traverse all the permutation of the node order, and find the smallest distance
        unordered_map<int,int> dp(node_num);
        int shortest_path = INT_MAX;
        for (int i = 0; i < node_num; i++) {
            int path = dfs(distances, i, (1 << i), node_num - 1, 0, dp);
            shortest_path = min(shortest_path, path);
        }
        return shortest_path;
    }
};