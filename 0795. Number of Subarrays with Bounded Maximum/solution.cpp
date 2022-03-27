class Solution {
    int count(vector<int>& nums, int limit) {
        int ans = 0, cnt = 0;
        for (auto n : nums) {
            cnt = (n <= limit)? cnt+1:0;
            ans += cnt;
        }
        return ans;
    }
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        // The answer will be the #(subarray <= right) - #(subarray <= left)
        return count(nums, right) - count(nums, left-1);
    }
};