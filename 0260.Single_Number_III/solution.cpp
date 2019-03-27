#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_result = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            xor_result ^= *it;
        }
        int bits_mask = 1;
        while(!(xor_result & bits_mask)) {
            bits_mask <<= 1;
        }
        int num1 = xor_result, num2 = xor_result;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (*it & bits_mask) {
                num1 ^= *it;
            } else {
                num2 ^= *it;
            }
        }
        vector<int> ret_nums;
        ret_nums.push_back(num1);
        ret_nums.push_back(num2);
        return ret_nums;
    }
};

int main() {
    vector<int> nums{1,2,1,3,2,5};
    Solution solution;
    vector<int> ret_nums = solution.singleNumber(nums);
    for (vector<int>::iterator it = ret_nums.begin(); it != ret_nums.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}