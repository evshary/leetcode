#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#if 1 // Using the same array
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int count = 0;
        vector<vector<char>> map(grid);
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[0].size(); j++) {
                if (map[i][j] == '1') {
                    count++;
                    doDFS(map, i, j);
                }
            }
        }
        return count;
    }
private:
    void doDFS(vector<vector<char>>& map, int row, int column) {
        if (row < 0 || column < 0 || row >= map.size() || column >= map[0].size() || map[row][column] == '0')
            return;
        map[row][column] = '0';
        doDFS(map, row-1, column);
        doDFS(map, row+1, column);
        doDFS(map, row, column-1);
        doDFS(map, row, column+1);
    }
};
#else
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int count = 0;
        seen.clear();
        vector<char> row;
        row.assign(grid[0].size(), 0);
        seen.assign(grid.size(), row);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (seen[i][j] == 0) {
                    seen[i][j] = 1;
                    if (grid[i][j] == '1') {
                        doBFS(grid, i, j);
                        count++;
                    }
                }
            }
        }
        return count;
    }
private:
    vector<vector<char>> seen;
    void doBFS(vector<vector<char>>& grid, int row, int column) {
        queue<pair<int, int>> q;
        q.push(make_pair(row, column));
        int i,j;
        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            if (i - 1 >= 0 && seen[i-1][j] == 0) {
                seen[i-1][j] = 1;
                if (grid[i-1][j] == '1')
                    q.push(make_pair(i-1, j));
            }
            if (i + 1 < seen.size() && seen[i+1][j] == 0) {
                seen[i+1][j] = 1;
                if (grid[i+1][j] == '1')
                    q.push(make_pair(i+1, j));
            }
            if (j - 1 >= 0 && seen[i][j-1] == 0) {
                seen[i][j-1] = 1;
                if (grid[i][j-1] == '1')
                    q.push(make_pair(i, j-1));
            }
            if (j + 1 < seen[0].size() && seen[i][j+1] == 0) {
                seen[i][j+1] = 1;
                if (grid[i][j+1] == '1')
                    q.push(make_pair(i, j+1));
            }
            q.pop();
        }
    }
};
#endif

int main() {
    vector<vector<vector<char>>> problems{{{'1','1','1','1','0'},
                                           {'1','1','0','1','0'},
                                           {'1','1','0','0','0'},
                                           {'0','0','0','0','0'},},
                                          {{'1','1','0','0','0'},
                                           {'1','1','0','0','0'},
                                           {'0','0','1','0','0'},
                                           {'0','0','0','1','1'},}
                                         };
    Solution solution;
    for (auto p : problems) {
        cout << solution.numIslands(p) << endl;
    }
    return 0;
}