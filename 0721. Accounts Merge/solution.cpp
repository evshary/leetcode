class Solution {
private:
	int find(vector<int>& fathers, int node) {
		if (fathers[node] == node) return node;
		fathers[node] = find(fathers, fathers[node]);
		return fathers[node];
	}
	void join(vector<int>& fathers, int node1, int node2) {
		int f1 = find(fathers, node1);
		int f2 = find(fathers, node2);
		if (f1 == f2) return;
		fathers[f2] = f1;
	}
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> fathers(accounts.size(), 0);
        unordered_map<string,int> email2id;
        // init father
        for (int i = 0; i < accounts.size(); i++) fathers[i] = i;
        // join
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
            	if (email2id.count(accounts[i][j])) {
            		join(fathers, email2id[accounts[i][j]], i);
            	} else {
            		email2id[accounts[i][j]] = i;
            	}
            }
        }
        // reorganize the group: note we need to use father id as key
        unordered_map<int,set<string>> new_accounts;
        for (auto & [email,id] : email2id) {
        	int fid = find(fathers, id);
        	new_accounts[fid].insert(email);
        }
        // output answer
        vector<vector<string>> ans;
        for (auto & [id,emails] : new_accounts) {
        	vector<string> tmp;
        	tmp.push_back(accounts[id][0]);
        	tmp.insert(tmp.end(), emails.begin(), emails.end());
        	ans.push_back(tmp);
        }
        return ans;
    }
};