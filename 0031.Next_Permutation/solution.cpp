#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot;
        if (nums.size() < 2) return;
        for (pivot = nums.size()-2; pivot >= 0; pivot--) {
            if (nums[pivot] < nums[pivot+1])
                break;
        }
        if (pivot >= 0) {
            int idx;
            for (idx = nums.size()-1; nums[pivot] >= nums[idx]; idx--);
            swap(nums[pivot], nums[idx]);
        }
        reverse(nums.begin()+pivot+1, nums.end());
    }
};

int main() {
    vector<vector<int>> problems{{1,2,3},{3,2,1},{1,1,5}};
    Solution solution;
    for (vector<vector<int>>::iterator p = problems.begin(); p != problems.end(); p++) {
        cout << "[";
        for (auto num : *p) cout << num << " ";
        cout << "]:";
        solution.nextPermutation(*p);
        for (auto num : *p) cout << num << " ";
        cout << endl;;
    }
    return 0;
}