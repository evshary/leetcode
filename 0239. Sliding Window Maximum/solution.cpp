class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int max_num = (dq.empty())? nums[i] : max(nums[i], nums[dq.front()]);
            if (i >= k - 1) ans.push_back(max_num);
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            while (!dq.empty() && dq.front() + k - 1 <= i) dq.pop_front();
        }
        return ans;
    }
};