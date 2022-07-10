class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min_num = INT_MAX;
        for (auto & n : nums) {
            if (n < 0) {
                // revert the n
                n = -n;
                min_num = min(min_num, n);
                k--;
            } else if (n == 0) {
                // ignore k while there is 0
                k = 0;                
            } else if (n > 0) {
                // get the smallest number
                min_num = min(min_num, n);
                break;
            }
            if (k == 0) break;
        }
        int total = 0;
        for (auto n : nums) total += n;
        if (k % 2 == 1) total -= min_num * 2;
        return total;
    }
};