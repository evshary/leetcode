#include <iostream>
#include <vector>
using namespace std;

#if 1 // dynamic table with two variables
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int prev1 = nums[0], prev2 = max(nums[0], nums[1]), tmp;
        for (int i = 2; i < nums.size(); i++) {
            tmp = max(prev1+nums[i], prev2);
            prev1 = prev2;
            prev2 = tmp;
        }
        return prev2;
    }
};
#elif 1 // dynamic table
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> d_table(nums.size(), 0);
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        d_table[0] = nums[0];
        d_table[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            d_table[i] = max(d_table[i-2]+nums[i], d_table[i-1]);
        }
        return d_table[nums.size()-1];
    }
};
#else // recursion
class Solution {
public:
    int rob(vector<int>& nums) {
        return rob_r(nums, 0);
    }
private:
    int rob_r(vector<int>& nums, int idx) {
        if (idx >= nums.size()) return 0;
        return max(rob_r(nums, idx+1), nums[idx]+rob_r(nums, idx+2));
    }
};
#endif

int main() {
    vector<vector<int>> problems{{1,2,3,1},{2,7,9,3,1},{2,1,1,2}};
    Solution solution;
    for (auto p : problems) {
        cout << "[";
        for (auto num : p) cout << num << " ";
        cout << "]: " << solution.rob(p) << endl;
    }
    return 0;
}