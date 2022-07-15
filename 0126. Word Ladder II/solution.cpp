#if 1  // Bidirectional BFS + DFS still TLE
class Solution {
private:
    unordered_map<string,unordered_set<string>> graph;
    unordered_map<string,bool> bfs_visited;
    unordered_map<string,bool> dfs_visited;
    vector<vector<string>> result;
    bool bfs(unordered_set<string>& layer, unordered_set<string>& opposite_layer, int& step) {
        unordered_set<string> new_layer;
        bool found = false;
        step++;
        for (auto & s : layer) {
            for (int i = 0; i < s.size(); i++) {
                string new_s = s;
                for (char c = 'a'; c <= 'z'; c++) {
                    new_s[i] = c;
                    if (!bfs_visited.count(new_s)) continue;
                    graph[s].insert(new_s);
                    graph[new_s].insert(s);
                    if (opposite_layer.count(new_s)) {
                        found = true;
                    }
                    if (bfs_visited[new_s] == false) {
                        bfs_visited[new_s] = true;
                        new_layer.insert(new_s);
                    }
                }
            }
        }
        swap(layer, new_layer);
        return found;
    }
    void dfs(vector<string>& path, string& endWord, int& path_size) {
        if (path.back() == endWord) {
            result.push_back(path);
            return;
        }
        if (path.size() >= path_size) return;
        for (auto& s : graph[path.back()]) {
            if (dfs_visited.count(s) && dfs_visited[s] == true) continue;
            path.push_back(s);
            dfs_visited[s] = true;
            dfs(path, endWord, path_size);
            path.pop_back();
            dfs_visited[s] = false;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> begin_layer, end_layer;
        int begin_step = 0, end_step = 0;
        for (auto & s : wordList) {
            bfs_visited[s] = false;
        }
        if (!bfs_visited.count(endWord)) return result;
        begin_layer.insert(beginWord);
        end_layer.insert(endWord);
        bfs_visited[beginWord] = bfs_visited[endWord] = true;
        while (!begin_layer.empty() && !end_layer.empty()) {
            if (bfs(begin_layer, end_layer, begin_step) || bfs(end_layer, begin_layer, end_step)) {
                break;
            }
        }
        vector<string> path = {beginWord};
        dfs_visited[beginWord] = true;
        int path_size = begin_step+end_step+1;
        dfs(path, endWord, path_size);
        return result;
    }
};
#elif 0 // Bidirectional BFS, still TLE
class Solution {
private:
    bool update_layer(vector<vector<string>>& layer, vector<vector<string>>& opposite_layer, unordered_map<string,bool>& visited) {
        unordered_set<string> opposite_last;
        for (auto & path : opposite_layer) {
            opposite_last.insert(path.back());
        }
        vector<vector<string>> new_layer;
        bool found = false;
        for (auto & path : layer) {
            string s = path.back();
            for (int i = 0; i < s.size(); i++) {
                string new_s = s;
                for (char c = 'a'; c <= 'z'; c++) {
                    new_s[i] = c;
                    if (!visited.count(new_s)) continue;
                    if (opposite_last.count(new_s)) {
                        found = true;
                    }
                    if (opposite_last.count(new_s) || visited[new_s] == false) {
                        visited[s] = true;
                        path.push_back(new_s);
                        new_layer.push_back(path);
                        path.pop_back();
                    }
                }
            }
        }
        swap(layer, new_layer);
        return found;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> begin_layer, end_layer, ans;
        unordered_map<string,bool> visited;
        for (auto s : wordList) {
            visited[s] = false;
        }
        if (!visited.count(endWord)) return ans;
        begin_layer.push_back({beginWord});
        end_layer.push_back({endWord});
        while (!begin_layer.empty() && !end_layer.empty()) {
            if (update_layer(begin_layer, end_layer, visited) || update_layer(end_layer, begin_layer, visited)) {
                for (auto & bpath : begin_layer) {
                    for (auto & epath : end_layer) {
                        if (bpath.back() == epath.back()) {
                            vector<string> new_path = bpath;
                            for (int i = epath.size()-2; i>=0; i--) new_path.push_back(epath[i]);
                            ans.push_back(new_path);
                        }
                    }
                }
                break;
            }
        }
        return ans;
    }
};
#else  // TLE now
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> visited;
        for (auto &s : wordList) {
        	visited[s] = false;
        }
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        while (!q.empty()) {
        	if (!ans.empty()) break;
        	int qsize = q.size();
        	vector<string> new_visited;
        	for (int i = 0; i < qsize; i++) {
        		vector<string> path = q.front();
        		q.pop();
        		string s = path.back();
        		if (s == endWord) ans.push_back(path);
        		if (!ans.empty()) continue;
        		for (int i = 0; i < s.size(); i++) {
        			string new_s = s;
        			for (int c = 'a'; c <= 'z'; c++) {
        				new_s[i] = c;
        				if (!visited.count(new_s) || visited[new_s] == true) continue;
        				new_visited.push_back(new_s);
        				path.push_back(new_s);
        				q.push(path);
        				path.pop_back();
        			}
        		}
        	}
        	// Set all the new nodes in this layer to visisted
        	// Do not repeat these nodes in the future
        	for (auto s : new_visited) {
        		visited[s] = true;
        	}
        }
        return ans;
    }
};
#endif