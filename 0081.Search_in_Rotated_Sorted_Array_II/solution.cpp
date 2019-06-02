#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        // Find out the rotate point
        int begin = 0, end = nums.size()-1, mid;
        while (begin <= end) {
            mid = begin + (end - begin)/2;
            //cout << "begin:" << begin << ", end:" << end << ", mid:" << mid << endl;
            if (nums[mid] == target) return true;
            if (nums[begin] == nums[end] && nums[begin] == nums[mid]) {
                begin++;
                end--;
            } else if (nums[mid] >= nums[begin]) {
                if (nums[mid] > target && nums[begin] <= target)
                    end = mid - 1;
                else
                    begin = mid + 1;
            } else {
                if (nums[mid] < target && nums[end] >= target)
                    begin = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    vector<pair<vector<int>,int>> problems{{{2,5,6,0,0,1,2},0}, // true 
                                           {{2,5,6,0,0,1,2},3}, // false
                                           {{1,3},3},           // true
                                           {{3,1},3},           // true
                                           {{4,4,4,4,4},4},     // true
                                           {{4,4,4,4,4},5},     // false
                                           {{1,2,1},2}};        // true
    Solution s;
    for (auto p : problems) {
        if (s.search(p.first, p.second))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}