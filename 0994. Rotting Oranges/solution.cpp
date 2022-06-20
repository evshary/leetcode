class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int fresh = 0;
        int rotten = 0;
        int row_size = grid.size();
        int col_size = grid[0].size();
        for (int r = 0; r < row_size; r++) {
            for (int c = 0; c < col_size; c++) {
                if (grid[r][c] == 1) {
                    fresh++;
                } else if (grid[r][c] == 2) {
                    rotten++;
                    q.push({r,c});
                }
            }
        }
        if (fresh == 0) return 0;
        int minutes = 0;
        while (!q.empty()) {
            if (fresh == 0) return minutes;
            minutes++;
            int cur_rotten_num = q.size();
            for (int i = 0; i < cur_rotten_num; i++) {
                vector<int> v = q.front();
                q.pop();
                if (v[0] > 0 && grid[v[0]-1][v[1]] == 1) {
                    grid[v[0]-1][v[1]] = 2;
                    q.push({v[0]-1, v[1]});
                    fresh--;
                }
                if (v[1] > 0 && grid[v[0]][v[1]-1] == 1) {
                    grid[v[0]][v[1]-1] = 2;
                    q.push({v[0], v[1]-1});
                    fresh--;
                }
                if (v[0] < row_size-1 && grid[v[0]+1][v[1]] == 1) {
                    grid[v[0]+1][v[1]] = 2;
                    q.push({v[0]+1, v[1]});
                    fresh--;
                }
                if (v[1] < col_size-1 && grid[v[0]][v[1]+1] == 1) {
                    grid[v[0]][v[1]+1] = 2;
                    q.push({v[0], v[1]+1});
                    fresh--;
                }
            }
        }
        return -1;
    }
};