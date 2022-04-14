class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int take = nums[0], not_take = 0;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (prev == nums[i]) {
                take += nums[i];
            } else if (prev == nums[i]-1) {
                int new_take = not_take + nums[i];
                int new_not_take = max(take, not_take);
                take = new_take;
                not_take = new_not_take;
            } else {
                not_take = max(take, not_take);
                take = not_take + nums[i];
            }
            prev = nums[i];
        }
        return max(take, not_take);
    }
};
