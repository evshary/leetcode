class Solution {
    vector<vector<int>> mapping;
    vector<bool> visited;
    void dfs(vector<int> & group, int i) {
        if (visited[i] == false) {
            visited[i] = true;
            group.push_back(i);
            for (int j = 0; j < mapping[i].size(); j++) {
                dfs(group, mapping[i][j]);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // check #connection < n-1 then impossible
        if (n - 1 > connections.size())
            return -1;
        // create mapping table
        mapping.resize(n);
        visited.resize(n, false);
        for (auto & c : connections) {
            mapping[c[0]].push_back(c[1]);
            mapping[c[1]].push_back(c[0]);
        }
        // dfs find group number
        int group_num = 0;
        for (int i = 0; i < mapping.size(); i++) {
            vector<int> group;
            dfs(group, i);
            if (!group.empty())
                group_num++;
        }
        // return group number - 1
        return group_num-1;
    }
};