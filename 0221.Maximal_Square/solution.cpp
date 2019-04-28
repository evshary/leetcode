#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int columns = matrix[0].size();
        vector<vector<int>> dynamic_table(rows, vector<int>(columns, 0));
        int max_side = 0;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == '1') {
                dynamic_table[i][0] = 1;
                max_side = max(max_side, dynamic_table[i][0]);
            }
        }
        for (int j = 0; j < columns; j++) {
            if (matrix[0][j] == '1') {
                dynamic_table[0][j] = 1;
                max_side = max(max_side, dynamic_table[0][j]);
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    dynamic_table[i][j] = 1 + min(min(dynamic_table[i-1][j],dynamic_table[i][j-1]), dynamic_table[i-1][j-1]);
                    max_side = max(max_side, dynamic_table[i][j]);
                }
            }
        }
        return max_side * max_side;
    }
};

int main() {
    Solution solution;
#if 0
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};
#else
    vector<vector<char>> matrix{{'0','1','1','0','1'},
                                {'1','1','0','1','0'},
                                {'0','1','1','1','0'},
                                {'1','1','1','1','0'},
                                {'1','1','1','1','1'},
                                {'0','0','0','0','0'}};
#endif
    cout << "Square: " << solution.maximalSquare(matrix) << endl;
    return 0;
}