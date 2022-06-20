class Solution {
private:
    unordered_map<string,vector<pair<string,double>>> mapping; // X: (Y,2), (Z,3),...
    unordered_map<string,bool> visited;
    unordered_map<string,double> result; // 'X/Y': 2
    void dfs(string s1, string s2, double val) {
        result[s1+'/'+s2] = val;
        for (auto v : mapping[s2]) {
            if (visited[v.first] == false) {
                visited[v.first] = true;
                dfs(s1, v.first, val * v.second);
                visited[v.first] = false;
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            mapping[equations[i][0]].push_back({equations[i][1], values[i]});
            mapping[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
        }
        for (auto m : mapping) {
            visited[m.first] = true;
            dfs(m.first, m.first, 1);
            visited[m.first] = false;
        }
        vector<double> ans;
        for (auto q : queries) {
            if (result.count(q[0]+'/'+q[1])) {
                ans.push_back(result[q[0]+'/'+q[1]]);
            } else {
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};