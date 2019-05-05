#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
#if 1
        int result, cmax, cmin;
        result = cmax = cmin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(cmax, cmin);
            cmax = max(nums[i], nums[i] * cmax);
            cmin = min(nums[i], nums[i] * cmin);
            result = max(result, cmax);
        }
        return result;
#else // Brute force
        int cur_num, max_num = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            cur_num = nums[i];
            max_num = max(max_num, cur_num);
            for (int j = i+1; j < nums.size(); j++) {
                cur_num *= nums[j];
                max_num = max(max_num, cur_num);
            }
        }
        return max_num;
#endif
    }
};

int main() {
    Solution solution;
    vector<vector<int>> problems{{2,3,-2,4},
                                 {-2,0,-1},
                                };
    for (auto p : problems) {
        cout << "p[";
        for (auto num : p) cout << num << " ";
        cout << "]:";
        cout << solution.maxProduct(p) << endl;
    }
    return 0;
}