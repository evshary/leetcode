class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int min_len = INT_MAX;
        int total_sum = 0;
        int cur_len = 0;
        while (right < nums.size()) {
            int r_num = nums[right];
            right++;
            total_sum += r_num;
            cur_len++;
            while (total_sum >= target && left < right) {
                min_len = min(min_len, cur_len);
                int l_num = nums[left];
                left++;
                total_sum -= l_num;
                cur_len--;
            }
        }
        return (min_len == INT_MAX)? 0:min_len;
    }
};