class Solution {
private:
    unordered_map<string,map<string,int>> arr_table;
	bool traverse(vector<string>& path, vector<vector<string>>& tickets) {
		if (path.size() == tickets.size() + 1) {
			return true;
		}
		string loc = path.back();
		for (auto & next_loc : arr_table[loc]) {
			if (next_loc.second == 0) continue;
			next_loc.second--;
			path.push_back(next_loc.first);
			if (traverse(path, tickets)) return true;
			path.pop_back();
			next_loc.second++;
		}
		return false;
	}
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto t : tickets) {
        	arr_table[t[0]][t[1]]++;
        }
        vector<string> path{"JFK"};
        traverse(path, tickets);
        return path;
    }
};