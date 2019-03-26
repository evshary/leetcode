#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;
        int med, count;
        while (low < high) {
            med = low + (high-low)/2;
            count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= med)
                    count++;
            }
            if (count <= med)
                low = med + 1;
            else
                high = med;
        }
        return low;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,3,4,2,2};
    cout << "solution: " << solution.findDuplicate(nums) << endl;
    return 0;
}