#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int smallest = INT_MAX, largest = INT_MIN;
        for (auto num : A) {
            if (num > largest)
                largest = num;
            if (num < smallest)
                smallest = num;
        }
        if (largest - smallest <= 2 * K)
            return 0;
        else
            return largest - smallest - (2 * K);
    }
};

int main() {
    vector<pair<vector<int>, int>> problems{{{1},0},
                                            {{0,10},2},
                                            {{1,3,6},3}};
    Solution solution;
    for (auto p : problems) {
        cout << "[";
        for (auto num : p.first) cout << num << ", ";
        cout << "], K=" << p.second << ": " << solution.smallestRangeI(p.first, p.second) << endl;
    }
    return 0;
}