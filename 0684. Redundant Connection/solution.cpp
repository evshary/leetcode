class Solution {
private:
    int find(vector<int>& fathers, int node) {
        if (fathers[node] == node) return node;
        fathers[node] = find(fathers, fathers[node]);
        return fathers[node]; 
    }
    void join(vector<int>& fathers, int node1, int node2) {
        int father1 = find(fathers, node1);
        int father2 = find(fathers, node2);
        if (father1 != father2) {
            fathers[father2] = father1;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> fathers(edges.size()+1);
        // init fathers
        for (int i = 1; i <= edges.size(); i++) {
            fathers[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (find(fathers, edges[i][0]) == find(fathers, edges[i][1])) {
                return edges[i];
            } else {
                join(fathers, edges[i][0], edges[i][1]);
            }
        }
        return {};
    }
};