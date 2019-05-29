#include <iostream>
#include <vector>
using namespace std;

#if 1 // Using BFS to get the result
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        vector<int> counters(n, 0);
        vector<bool> exist(n, true); // Assume every node exist 1.
        // Build adjacent list
        for (auto e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
            counters[e[0]]++;
            counters[e[1]]++;
        }
        // The result will only left 1 or 2
        while (n != 1 && n != 2) {
            vector<int> q;
            if (n == 1 || n == 2) break;
            // Get the node which has only one neighbor and delete
            for (int i = 0; i < counters.size(); i++) {
                if (counters[i] == 1) {
                    q.push_back(i);
                    exist[i] = false; // remove the node itself
                }
            }
            // Decrease the #neighbor count
            for (auto num : q) {
                counters[num]--;
                for (auto neighbor : adj_list[num]) {
                    counters[neighbor]--;
                }
            }
            if (q.size() == 0) break; // avoid infinte loop
            n -= q.size();
        };
        // found out what is left
        vector<int> result;
        for (int i = 0; i < exist.size(); i++) {
            if (exist[i]) result.push_back(i);
        }
        return result;
    }
};
#elif 1 // TLE while n is large
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph.clear();
        vector<bool> rows(n, false);
        graph.assign(n, rows);
        for (auto e : edges) {
            graph[e[0]][e[1]] = true;
            graph[e[1]][e[0]] = true;
        }
        vector<int> result;
        int min_depth = INT_MAX;
        for (int i = 0; i < n; i++) {
            vector<bool> walked(n, false);
            int tmp_depth = findMaxDepth(i, n, walked);
            if (tmp_depth <= min_depth) {
                if (tmp_depth < min_depth)
                    result.clear();
                result.push_back(i);
                min_depth = tmp_depth;
            }
        }
        return result;
    }
private:
    vector<vector<bool>> graph;
    int findMaxDepth(int point, int n, vector<bool>& walked) {
        walked[point] = true;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (walked[i]) continue;
            if (graph[point][i])
                result = max(result, 1+findMaxDepth(i, n, walked));
        }
        return result;
    }
};
#endif

int main() {
#if 0
    vector<vector<int>> edges{{1, 0}, {1, 2}, {1, 3}};
    int n = 4;
#elif 1
    vector<vector<int>> edges{{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    int n = 6;
#elif 1
    vector<vector<int>> edges{{0, 1}};
    int n = 2;
#endif
    Solution s;
    vector<int> result = s.findMinHeightTrees(n, edges);
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}