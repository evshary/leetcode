class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // pair definition: {dst, color}, color: 0=>red, 1=>blue
        vector<vector<pair<int,int>>> path_table(n);
        vector<int> answer(n, -1);
        for (auto & e : redEdges) {
            path_table[e[0]].push_back({e[1], 0});
        }
        for (auto & e : blueEdges) {
            path_table[e[0]].push_back({e[1], 1});
        }
        queue<vector<int>> q;
        answer[0] = 0;
        q.push({0, 0, -1});  // dst, shortest path, color
        while (!q.empty()) {
            vector<int> cur_node = q.front();
            q.pop();
            for (auto & [dst, color] : path_table[cur_node[0]]) {
                if (dst != -1 && color != cur_node[2]) { // not visited and different color
                    answer[dst] = (answer[dst] == -1)? (cur_node[1]+1):min(answer[dst],cur_node[1]+1);
                    q.push({dst, cur_node[1]+1, color});
                    dst = -1;
                }
            }
        }
        return answer;
    }
};

