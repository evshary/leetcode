class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int result = 0;
        int product = 1;
        while (right < nums.size()) {
            int r = nums[right];
            right++;
            product *= r;
            while (left < right && product >= k) {
                int l = nums[left];
                left++;
                product /= l;
            }
            result += right - left;
        }
        return result;
    }
};