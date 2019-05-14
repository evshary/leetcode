#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int low = 0, high = nums.size()-1;
        int idx = 0;
        if (nums[low] > nums[high]) {
            // get the pivot.
            while(low != high) {
                idx = low + (high - low) / 2;
                if (nums[idx] > nums[0]) {
                    if (nums[idx+1] < nums[0])
                        break;
                    else
                        low = idx;
                } else {
                    high = idx;
                }
            }
            // check the target is in first part or second part
            if (target > nums[0]) {
                low = 0;
                high = idx;
            } else if (target < nums[0]) {
                low = idx + 1;
                high = nums.size() - 1;
            } else
                return 0;
        }
        // Start binary search
        while (low <= high) {
            idx = low + (high - low) / 2;
            if (nums[idx] > target) {
                high = idx - 1;
            } else if (nums[idx] < target) {
                low = idx + 1;
            } else
                return idx;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<pair<vector<int>,int>> problems{
                                           {{4,5,6,7,0,1,2},0},
                                           {{1,3},3},
                                           {{3,1},1},
                                          };
    for (auto p : problems) {
        cout << solution.search(p.first, p.second) << endl;
    }
    return 0;
}