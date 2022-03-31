#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int avg;
        vector<int> result{-1, -1};
        // binary search for target
        while (left <= right) {
            avg = (left + right) / 2;
            if (nums[avg] > target) {
                right = avg - 1;
            } else if (nums[avg] < target) {
                left = avg + 1;
            } else
                break;
        }
        // We don't find the target
        if (left > right) return result;
        result[0] = result[1] = avg;
        // find the left of the nums[avg]
        left = 0;
        right = result[0]-1;
        while (left <= right) {
            avg = (left + right)/2;
            if (nums[avg] == target)
                right = avg - 1;
            else
                left = avg + 1;
        }
        result[0] = left;
        // find the right of the nums[avg]
        left = result[0]+1;
        right = nums.size()-1;
        while (left <= right) {
            avg = (left + right)/2;
            if (nums[avg] == target)
                left = avg + 1;
            else
                right = avg - 1;
        }
        result[1] = right;
        return result;
    }
};

int main() {
    vector<pair<vector<int>,int>> problems{
                                          {{5,7,7,8,8,10},8}, 
                                          {{5,7,7,8,8,10},6}, 
                                          };
    Solution solution;
    for (auto p : problems) {
        vector<int> result = solution.searchRange(p.first, p.second);
        for (auto num : result) cout << num << " ";
        cout << endl;
    }
    return 0;
}