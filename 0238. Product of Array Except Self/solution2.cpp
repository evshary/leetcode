class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        for (int i = 1; i < ans.size(); i++) {
            ans[i] = nums[i] * ans[i-1];
        }
        int multiplier = 1;
        for (int i = ans.size()-1; i > 0; i--) {
            ans[i] = ans[i-1] * multiplier;
            multiplier *= nums[i];
        }
        ans[0] = multiplier;
        return ans;
    }
};