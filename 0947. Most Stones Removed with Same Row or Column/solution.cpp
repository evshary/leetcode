class Solution {
	unordered_map<int, vector<int>> row_hash;
	unordered_map<int, vector<int>> col_hash;
    void dfs(int idx, vector<vector<int>>& stones, vector<bool>& visited) {
		visited[idx] = true;
		for (auto i : row_hash[stones[idx][0]]) {
			if (visited[i] == false) {
				dfs(i, stones, visited);
			}
		}
		for (auto i : col_hash[stones[idx][1]]) {
			if (visited[i] == false) {
				dfs(i, stones, visited);
			}
		}
    }
public:
    int removeStones(vector<vector<int>>& stones) {
		vector<bool> visited(stones.size(), false);
		for (int i = 0; i < stones.size(); i++) {
			row_hash[stones[i][0]].push_back(i);
			col_hash[stones[i][1]].push_back(i);
		}
		int union_group = 0;
		for (int i = 0; i < stones.size(); i++) {
			if (visited[i] == false) {
				dfs(i, stones, visited);
				union_group++;
			}
		}
        return stones.size() - union_group;
    }
};
#if 0  // TLE
class Solution {
    
    int max_rm_stone = 0;
    void dfs(vector<vector<int>> & stones, vector<vector<bool>>& stone_pos, int rm_stone) {
		max_rm_stone = max(max_rm_stone, rm_stone);
        for (auto & s: stones) {
			if (stone_pos[s[0]][s[1]] == false) continue;
			stone_pos[s[0]][s[1]] = false;
			bool repeat = false;
			for (int r = 0; r < stone_pos.size(); r++) {
                if (stone_pos[r][s[1]]) {
				    repeat = true;
                    break;
                }
			}
			for (int c = 0; c < stone_pos[s[0]].size(); c++) {
                if (repeat || stone_pos[s[0]][c]) {
				    repeat = true;
                    break;
                }
			}
			if (repeat)
				dfs(stones, stone_pos, rm_stone+1);
			stone_pos[s[0]][s[1]] = true;
		}
    }
public:
    int removeStones(vector<vector<int>>& stones) {
		int max_n = 0;
		for (auto & s : stones) {
			max_n = max(max_n, max(s[0],s[1]));
		}
		vector<vector<bool>> stone_pos(max_n+1, vector<bool>(max_n+1, false));
		for (auto & s : stones) {
			stone_pos[s[0]][s[1]] = true;
		}
        dfs(stones, stone_pos, 0);
        return max_rm_stone;
    }
};
#endif
#if 0  // TLE 2
class Solution {
    void dfs(int x, int y, vector<vector<bool>>& stone_pos) {
		stone_pos[x][y] = false;
		for (int r = 0; r < stone_pos.size(); r++) {
			if (stone_pos[r][y]) {
				dfs(r, y, stone_pos);
			}
		}
		for (int c = 0; c < stone_pos[x].size(); c++) {
			if (stone_pos[x][c]) {
				dfs(x, c, stone_pos);
			}
		}
    }
public:
    int removeStones(vector<vector<int>>& stones) {
		int max_n = 0;
		for (auto & s : stones) {
			max_n = max(max_n, max(s[0],s[1]));
		}
		vector<vector<bool>> stone_pos(max_n+1, vector<bool>(max_n+1, false));
		for (auto & s : stones) {
			stone_pos[s[0]][s[1]] = true;
		}
		int union_group = 0;
		for (auto & s : stones) {
			if (stone_pos[s[0]][s[1]]) {
				dfs(s[0], s[1], stone_pos);
				union_group++;
			}
		}
        return stones.size() - max_rm_stone;
    }
};
#endif