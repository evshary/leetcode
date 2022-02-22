class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool chance = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                if (chance) {
                    chance = false;
                } else {
                    return false;
                }
                int max = (i+1 != nums.size())? nums[i+1]:100000;
                int min = (i != 1)? nums[i-2]:-100000;
                if ((min > nums[i-1] || nums[i-1] > max) &&
                     (min > nums[i] || nums[i] > max))
                    return false;
            }
        }
        return true;
    }
};