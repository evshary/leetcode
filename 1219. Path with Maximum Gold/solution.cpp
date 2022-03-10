class Solution {
    int max_gold = 0;
    void findNextStep(int row, int col, vector<vector<int>>& grid, int gold) {
        int cur_gold = grid[row][col];
        max_gold = max(max_gold, gold+cur_gold);
        grid[row][col] = 0;
        if (row > 0 && grid[row-1][col] != 0)
            findNextStep(row-1, col, grid, gold+cur_gold);
        if (row < grid.size()-1 && grid[row+1][col] != 0)
            findNextStep(row+1, col, grid, gold+cur_gold);
        if (col > 0 && grid[row][col-1] != 0)
            findNextStep(row, col-1, grid, gold+cur_gold);
        if (col < grid[row].size()-1 && grid[row][col+1] != 0)
            findNextStep(row, col+1, grid, gold+cur_gold);
        grid[row][col] = cur_gold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] != 0) {
                    findNextStep(row, col, grid, 0);
                }
            }
        }
        return max_gold;
    }
};
