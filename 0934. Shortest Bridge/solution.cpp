class Solution {
	int dirs[5] = {0, 1, 0, -1, 0};
    void dfs(int r, int c, vector<vector<int>>& grid, vector<pair<int,int>>& q) {
        if (min(r, c) >= 0 && max(r, c) < grid.size() && grid[r][c] == 1) {
            grid[r][c] = 2;
            q.push_back(make_pair(r, c));
			for (int d = 0; d < 4; d++) {
				dfs(r+dirs[d], c+dirs[d+1], grid, q);
			}
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>> q;
		// find the first island
		for (int r = 0; q.empty() && r < grid.size(); r++) {
			for (int c = 0; q.empty() && c < grid[r].size(); c++) {
				if (grid[r][c] == 1)
					dfs(r, c, grid, q);
			}
		}
		// BFS
		while (!q.empty()) {
			vector<pair<int,int>> new_q;
			for (auto [x, y] : q) {
			    for (int d = 0; d < 4; d++) {
					int r = x + dirs[d];
					int c = y + dirs[d+1];
					if (min(r, c) >= 0 && max(r, c) < grid.size()) {
						if (grid[r][c] == 0) {
							grid[r][c] = grid[x][y] + 1;
							new_q.push_back(make_pair(r, c));
						} else if (grid[r][c] == 1) {
							return grid[x][y] - 2;
						} 
					}
				}
			}
			swap(q, new_q);
		}
		return 0;
    }
};

#if 0  // takes more time
class Solution {
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& first_island) {
        if (r >= 0 && c >= 0 && r < grid.size() && c < grid.size() && grid[r][c] == 1) {
            grid[r][c] = 0;
            first_island.push_back(vector<int>{r, c});
            dfs(r-1, c, grid, first_island);
            dfs(r+1, c, grid, first_island);
            dfs(r, c-1, grid, first_island);
            dfs(r, c+1, grid, first_island);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<int>> first_island;
        int min_bridge = 201;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                if (grid[r][c] == 1) {
                    if (first_island.empty()) {
                        // DFS
                        dfs(r, c, grid, first_island);
                    } else {
                        // Compare with the first island
                        for (auto & p : first_island) {
                            min_bridge = min(min_bridge, abs(p[0]-r) + abs(p[1]-c) - 1);
                        }
                    }
                }
            }
        }
        return min_bridge;
    }
};
#endif
