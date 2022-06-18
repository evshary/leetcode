class Solution {
private:
    bool isValid(vector<string>& way, int pos_r, int pos_c) {
        for (int r = pos_r-1; r >= 0; r--) {
            if (way[r][pos_c] == 'Q') return false;
        }
        for (int r = pos_r-1, c = pos_c-1; r >= 0 && c >= 0; r--, c--) {
            if (way[r][c] == 'Q') return false;
        }
        for (int r = pos_r-1, c = pos_c+1; r >= 0 && c < way.size(); r--, c++) {
            if (way[r][c] == 'Q') return false;
        }
        return true;
    }
    void traverse(vector<vector<string>>& result, vector<string>& way, int k, int n) {
        if (k == n) {
            result.push_back(way);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (isValid(way, k, c)) {
                way[k][c] = 'Q';
                traverse(result, way, k+1, n);
                way[k][c] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string row = "";
        for (int c = 0; c < n; c++) row += ".";
        vector<string> way(n, row);
        traverse(result, way, 0, n);
        return result;
    }
};