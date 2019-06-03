#include <iostream>
#include <vector>
using namespace std;

#if 1
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int idx;
        for (int i = 0; i < nums.size(); i++) {
            idx = abs(nums[i])-1;
            nums[idx] = (nums[idx] > 0)?-nums[idx]:nums[idx];
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                result.push_back(i+1);
            else
                nums[i] = -nums[i]; // recover the nums[i]
        }
        return result;
    }
};
#elif 1 // with extra space
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> tables(nums.size(), 1);
        vector<int> result;
        for (auto num : nums)
            tables[num-1]--;
        for (int i = 0; i < tables.size(); i++) {
            if (tables[i] == 1)
                result.push_back(i+1);
        }
        return result;
    }
};
#endif

int main() {
    vector<int> nums{4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> result = s.findDisappearedNumbers(nums);
    for (auto num : result)
        cout << num << " ";
    cout << endl;
    return 0;
}