#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        if (A.empty()) return 0;
        sort(A.begin(), A.end());
        int smallest = A[0], largest = A[A.size()-1];
        int ret = largest - smallest;
        for (int i = 1; i < A.size(); i++) {
            largest = max(largest, A[i-1] + 2 * K);
            smallest = min(A[i], A[0] + 2 * K);
            ret = min(ret, largest - smallest);
        }
        return ret;
    }
};

int main() {
    vector<pair<vector<int>, int>> problems{{{1},0},
                                            {{0,10},2},
                                            {{1,3,6},3},
                                            {{9,10,5,9},5},
                                            {{3,4,7,0},5}};
    Solution solution;
    for (auto p : problems) {
        cout << "[";
        for (auto num : p.first) cout << num << ", ";
        cout << "], K=" << p.second << ": " << solution.smallestRangeII(p.first, p.second) << endl;
    }
    return 0;
}