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
        if (father1 == father2) return;
        fathers[father2] = father1;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        vector<int> fathers(n);
        // init
        for (int i = 0; i < n; i++) {
            fathers[i] = i;
        }
        // connect
        for (int i = 0; i < connections.size(); i++) {
            join(fathers, connections[i][0], connections[i][1]);
        }
        int group = 0;
        // Count the number of group
        for (int i = 0; i < fathers.size(); i++) {
            if (i == fathers[i]) group++;
        }
        return group-1;
    }
};