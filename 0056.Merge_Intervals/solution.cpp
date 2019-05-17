#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare_func(vector<int> first, vector<int> second) {
    if (first[0] < second[0])
        return true;
    else
        return false;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), compare_func);
        if (intervals.empty()) return result;
        int first = intervals[0][0], second = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= first && intervals[i][0] <= second) {
                first = min(first, intervals[i][0]);
                second = max(second, intervals[i][1]);
            } else {
                result.push_back({first, second});
                first = intervals[i][0];
                second = intervals[i][1];
            }
        }
        result.push_back({first, second});
        return result;
    }
};

int main() {
    vector<vector<int>> p{{2,6},{8,10},{15,18},{1,3}};
    Solution solution;
    vector<vector<int>> result = solution.merge(p);
    for (auto e : result) {
        cout << e[0] << " " << e[1] << endl;
    }
    return 0;
}