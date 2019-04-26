#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
#if 0
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int low, medium, high = n;
        for (vector<vector<int>>::iterator rows = matrix.begin(); rows != matrix.end(); rows++) {
            low = 0;
            while(true) {
                medium = (high+low)/2;
                if ((*rows)[medium] > target)
                    high = medium;
                else if ((*rows)[medium] < target)
                    low = medium+1;
                else
                    return true;
                if (low == high)
                    break;
            }
        }
        return false;
#else
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int i = 0, j = n - 1;
        while(i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
#endif
    }
};

int main() {
    vector<vector<int>> matrix{
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 20;
    Solution solution;
    if (solution.searchMatrix(matrix, target))
        cout << "target " << target << ": true" << endl;
    else
        cout << "target " << target << ": false" << endl;
    return 0;
}