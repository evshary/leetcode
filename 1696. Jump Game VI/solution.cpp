#if 1 // Monotonic queue
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int end = nums.size()-1;
        vector<int> dp(nums.size());
        deque<int> deq;
        for (int i = end; i >= 0; i--) {
            dp[i] = nums[i] + ((deq.empty())? 0:dp[deq.front()]);
            while (!deq.empty() && deq.front() >= i + k) deq.pop_front();
            while (!deq.empty() && dp[deq.back()] < dp[i]) deq.pop_back();
            deq.push_back(i);
        }
        return dp[0];
    }
};
#else // TLE
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int end = nums.size()-1;
        vector<int> dp(nums.size());
        dp[end] = nums[end];
        for (int i = end - 1; i >= 0; i--) {
            int max_num;
            if (i + k >= end)
                max_num = *max_element(dp.begin() + i + 1, dp.end());
            else
                max_num = *max_element(dp.begin() + i + 1, dp.begin() + i + 1 + k);
            dp[i] = nums[i] + max_num;
        }
        return dp[0];
    }
};
#endif