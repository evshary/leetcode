class Solution {
    vector<bool> visited;
    vector<vector<int>> maping;
    vector<int> group_idx;
    string group_ch;
    void dfs(string & s, int i) {
        if (visited[i] == false) {
            group_idx.push_back(i);
            group_ch += s[i];
            visited[i] = true;
            for (auto m : maping[i]) {
                dfs(s, m);
            }
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        visited.resize(s.size(), false);
        maping.resize(s.size());
        for (auto & p : pairs) {
            maping[p[0]].push_back(p[1]);
            maping[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < s.size(); i++) {
            group_idx.clear();
            group_ch = "";
            dfs(s, i);
            sort(group_idx.begin(), group_idx.end());
            sort(group_ch.begin(), group_ch.end());
            for (int j = 0; j < group_idx.size(); j++) {
                s[group_idx[j]] = group_ch[j];
            }
        }
        return s;
    }
};