#include <iostream>
#include <vector>
using namespace std;

#if 1 // only use O(k)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rows(rowIndex+1, 0);
        for (int i = 0; i < rowIndex+1; i++) {
            rows[i] = 1;
            for (int j = i-1; j > 0; j--) {
                rows[j] = rows[j] + rows[j-1];
            }
        }
        return rows;
    }
};
#else  // use O(2k)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rows[2];
        rows[0].push_back(1);
        for (int i = 1; i < rowIndex+1; i++) {
            rows[i%2].clear();
            rows[i%2].push_back(1);
            for (int j = 1; j < rows[(i-1)%2].size(); j++) {
                rows[i%2].push_back(rows[(i-1)%2][j-1]+rows[(i-1)%2][j]);
            }
            rows[i%2].push_back(1);
        }
        return rows[rowIndex % 2];
    }
};
#endif

int main() {
    Solution s;
    int rowIndex = 3;
    for (auto num : s.getRow(3)) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}