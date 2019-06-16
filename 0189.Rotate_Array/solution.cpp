#include <iostream>
#include <vector>
using namespace std;

#if 1 // We can use mod to find the solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
#else
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k < nums.size()) {
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin()+k);
            reverse(nums.begin()+k, nums.end());
        } else {
            for (int i = 0; i < k; i++) {
                reverse(nums.begin(), nums.end());
                reverse(nums.begin()+1, nums.end());
            }
        }
    }
};
#endif

int main() {
#if 0
    vector<int> nums{1,2,3,4,5,6,7};
    int k = 3;
#elif 1
    vector<int> nums{-1};
    int k = 2;
#endif
    Solution s;
    s.rotate(nums, k);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}