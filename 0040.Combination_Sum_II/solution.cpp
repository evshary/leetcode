#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        result.clear();
        priv_candidates = candidates;
        sort(priv_candidates.begin(), priv_candidates.end());
        combination_r(v, 0, target);
        return result;
    }
private:
    void combination_r(vector<int> &v, int idx, int target) {
        if (target == 0) {
            result.push_back(v);
            return;
        }
        int tmp_idx = idx;
        while (tmp_idx < priv_candidates.size() && target - priv_candidates[idx] >= 0) {
            if (tmp_idx == idx || priv_candidates[tmp_idx] != priv_candidates[tmp_idx-1]) {
                v.push_back(priv_candidates[tmp_idx]);
                combination_r(v, tmp_idx+1, target-priv_candidates[tmp_idx]);
                v.pop_back();
            }
            tmp_idx++;
        }
    }
    vector<vector<int>> result;
    vector<int> priv_candidates;
};

int main() {
#if 0
    vector<int> candidates{10,1,2,7,6,1,5};
    int target = 8;
#elif 1
    vector<int> candidates{2,5,2,1,2};
    int target = 5;
#endif
    Solution s;
    for ( auto v : s.combinationSum2(candidates, target)) {
        for (auto num : v) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}