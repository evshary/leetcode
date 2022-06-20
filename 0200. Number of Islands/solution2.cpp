class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r_size = grid.size();
        int c_size = grid[0].size();
        int island_num = 0;
        for (int r = 0; r < r_size; r++) {
            for (int c = 0; c < c_size; c++) {
                if (grid[r][c] != '1') continue;
                island_num++;
                queue<vector<int>> q;
                q.push({r, c});
                while (!q.empty()) {
                    vector<int> v = q.front();
                    q.pop();
                    if (v[0] - 1 >= 0 && grid[v[0]-1][v[1]] == '1') {
                        q.push({v[0]-1, v[1]});
                        grid[v[0]-1][v[1]] = '2';
                    }
                    if (v[1] - 1 >= 0 && grid[v[0]][v[1]-1] == '1') {
                        q.push({v[0], v[1]-1});
                        grid[v[0]][v[1]-1] = '2';
                    }
                    if (v[0] + 1 < r_size && grid[v[0]+1][v[1]] == '1') {
                        q.push({v[0]+1, v[1]});
                        grid[v[0]+1][v[1]] = '2';
                    }
                    if (v[1] + 1 < c_size && grid[v[0]][v[1]+1] == '1') {
                        q.push({v[0], v[1]+1});
                        grid[v[0]][v[1]+1] = '2';
                    }
                }
            }
        }
        return island_num;
    }
};