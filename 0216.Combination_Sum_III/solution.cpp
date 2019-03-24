#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void combinationSum3_r(vector<int> tmp_list, int num, int sum) {
        if (tmp_list.size() > _k) {
            return;
        }
        if (sum == 0) {
            if (tmp_list.size() == _k)
                result.push_back(tmp_list);
            return;
        }
        if (sum < 0 || num > 9)
            return;
        //cout << "no num " << num << endl;
        combinationSum3_r(tmp_list, num+1, sum);
        tmp_list.push_back(num);
        //cout << "use num " << num << endl;
        combinationSum3_r(tmp_list, num+1, sum-num);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp_list;
        _k = k; 
        _n = n;
        combinationSum3_r(tmp_list, 1, n);
        return result;
    }

private:
    vector<vector<int>> result;
    int _k;
    int _n;
};

int main() {
#if 0
    int k = 3, n = 9;
#elif 0
    int k = 2, n = 18;
#elif 1
    int k = 3, n = 15;
#endif
    Solution solution;
    vector<vector<int>> result = solution.combinationSum3(k, n);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}