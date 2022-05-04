class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd_ptr = 0, even_ptr = 0;
        while (odd_ptr < nums.size()) {
            if (nums[odd_ptr] % 2 == 0) {
                swap(nums[odd_ptr], nums[even_ptr]);
                even_ptr++;
            }
            odd_ptr++;
        }
        return nums;
    }
};