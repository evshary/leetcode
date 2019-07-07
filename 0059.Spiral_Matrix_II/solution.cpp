#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n < 0) return {};
        int direction = 0; // 0:right, 1:down, 2:left, 3:up
        int row_b = 0, row_e = n-1, col_b=0, col_e=n-1;
        int cur_row = 0, cur_col = 0;
        int matrix_size = n * n;
        vector<int> line(n, 0);
        vector<vector<int>> result(n, line);
        for (int i = 1; i <= matrix_size; i++) {
            //cout << "i=" << i << ",cur_row=" << cur_row << ",cur_col=" << cur_col << endl;
            result[cur_row][cur_col] = i;
            if (direction == 0) {
                if (cur_col == col_e) {
                    direction = 1;
                    row_b++;
                    cur_row++;
                } else {
                    cur_col++;
                }
            } else if (direction == 1) {
                if (cur_row == row_e) {
                    direction = 2;
                    col_e--;
                    cur_col--;
                } else {
                    cur_row++;
                }
            } else if (direction == 2) {
                if (cur_col == col_b) {
                    direction = 3;
                    row_e--;
                    cur_row--;
                } else {
                    cur_col--;
                }
            } else if (direction == 3) {
                if (cur_row == row_b) {
                    direction = 0;
                    col_b++;
                    cur_col++;
                } else {
                    cur_row--;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix;
    Solution s;
    int n = 10;
    matrix = s.generateMatrix(n);
    for (auto v : matrix) {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}