class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        unsigned long odd = 0;
        unsigned long even = 0;
        int nums_size = nums.size();
        for (int i = 1; i < nums_size; i++) {
            if (i % 2 == 0)  // even
                even += nums[i];
            else             // odd
                odd += nums[i];
        }

        int result = (odd == even)?1:0;
        for (int i = 1; i < nums_size; i++) {
            if (i % 2 == 0)  // even
                even += -nums[i]+nums[i-1];
            else             // odd
                odd += -nums[i]+nums[i-1];
            if (odd == even)
                result++;
        }

        return result;
    }
};