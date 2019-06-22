#include <iostream>
#include <vector>
using namespace std;

#if 1
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        bool isColZero = false;
        // record zero in the first row/column
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) isColZero = true;
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // transform to zero based on first row/column
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        // transform row to zero based on matrix[0][0]
        if (matrix[0][0] == 0) {
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
        // transform col to zero based on isColZero
        if (isColZero) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
#else // use unused value as modified
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        for (int i = 0; i < matrix.size(); i++) {
            bool zero_line = false;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0)
                    zero_line = true;
            }
            for (int j = 0; j < matrix[i].size(); j++) {
                if (zero_line && matrix[i][j] != 0) 
                    matrix[i][j] = INT_MIN;
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            bool zero_line = false;
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][j] == 0)
                    zero_line = true;
            }
            for (int i = 0; i < matrix.size(); i++) {
                if (zero_line && matrix[i][j] != 0) 
                    matrix[i][j] = INT_MIN;
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == INT_MIN)
                    matrix[i][j] = 0;
            }
        }
    }
};
#endif

int main() {
#if 1
    vector<vector<int>> matrix{{1,1,1},
                               {1,0,1},
                               {1,1,1}};
#elif 1
    vector<vector<int>> matrix{{-2147483648},{2},{3}};
#elif 1
    vector<vector<int>> matrix{{0,1,2,0},
                               {3,4,5,2},
                               {1,3,1,5}};
#elif 1
    vector<vector<int>> matrix{{1,1,1},
                               {0,1,2}};
#endif
    Solution s;
    s.setZeroes(matrix);
    for (auto v : matrix) {
        for (auto num : v)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}