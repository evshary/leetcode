class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
#if 1
        int num1 = nums[0], num2 = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > num2) { // larger than num2 means also larger than num1
                return true;
            }
            if (nums[i] > num1) { // num2 > nums[i] > num1: update num2
                num2 = nums[i];
            } else {  // nums[i] <= num1: update num1
                num1 = nums[i];
            }
        }
        return false;
#else // O(N^2) LTE
        vector<bool> larger(nums.size(), false);
        int large_num = nums[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] < large_num) {
                larger[i] = true;
            } else {
                large_num = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] < nums[j] && larger[j] == true) {
                    return true;
                }
            }
        }
        return false;
#endif
    }
};