class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> odd_indexs = {-1};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1)
                odd_indexs.push_back(i);
        }
        odd_indexs.push_back(nums.size());
        int res = 0;
        for (int i = 0; i + k + 1 < odd_indexs.size(); i++) {
            res += (odd_indexs[i+1] - odd_indexs[i]) * (odd_indexs[i+k+1] - odd_indexs[i+k]);
        }
        return res;
#if 0 // O(N^2) over time
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int odd_num = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % 2 != 0) {
                    odd_num++;
                }
                if (odd_num > k) {
                    break;
                } else if (odd_num == k) {
                    res++;
                }
            }
        }
        return res;
#endif
    }
};