class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        bool repeat = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[idx]) {
                if (repeat)
                    continue;
                repeat = true;
            } else {
                repeat = false;
            }
            idx++;
            nums[idx] = nums[i];
        }
        return idx+1;
    }
};
