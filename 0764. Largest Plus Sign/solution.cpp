class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> matrix(n, vector<int>(n, 1));
        for (auto &m : mines) {
            matrix[m[0]][m[1]] = 0;
        }
        vector<vector<int>> left, right, top, down;
        left = right = top = down = matrix;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int x = n-1-r, y = n-1-c;
                if (r > 0 && top[r][c] == 1) top[r][c] += top[r-1][c];
                if (c > 0 && left[r][c] == 1) left[r][c] += left[r][c-1];
                if (r > 0 && down[x][y] == 1) down[x][y] += down[x+1][y];
                if (c > 0 && right[x][y] == 1) right[x][y] += right[x][y+1];
            }
        }
        int result = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                result = max(result, min({top[r][c], left[r][c], down[r][c], right[r][c]}));
            }
        }
        return result;
    }
};
