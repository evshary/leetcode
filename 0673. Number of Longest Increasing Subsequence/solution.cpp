class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> len(nums.size(), 1);
        vector<int> cnt(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (len[j]+1 > len[i]) {
                        cnt[i] = cnt[j];
                    } else if (len[j]+1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                    len[i] = max(len[i], len[j] + 1);
                }
            }
        }
        int ans = 0, max_len = 0;
        max_len = *max_element(len.begin(), len.end());
        for (int i = 0; i < nums.size(); i++) {
            if (len[i] == max_len) ans += cnt[i];
        }
        return ans;
    }
};