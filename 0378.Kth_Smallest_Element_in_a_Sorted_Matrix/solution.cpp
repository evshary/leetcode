#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m_size = matrix.size();
        if (m_size == 0) return 0;
        int low = matrix[0][0];
        int high = matrix[m_size-1][m_size-1];
        while(high > low) {
            int mid = low + (high - low)/2;
            int num = 0;
            for (int i = 0; i < m_size; i++) {
                num += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (k <= num)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main() {
    vector<vector<int>> matrix{{ 1,  5,  9},
                               {10, 11, 13},
                               {12, 13, 15}};
    int k = 8;
    Solution solution;
    cout << solution.kthSmallest(matrix, k);
    return 0;
}