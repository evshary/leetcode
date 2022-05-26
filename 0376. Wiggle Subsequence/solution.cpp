class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
#if 1 // simpler but not intuitive
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                up = down + 1;
            } else if (nums[i] < nums[i-1]) {
                down = up + 1;
            }
        }
        return max(up, down);
#elif 1 // O(N)
        pair<int,int> up = {nums[0], 1};
        pair<int,int> down = {nums[0], 1};
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > down.first) {
                if (down.second+1 > up.second) {
                    up.first = nums[i];
                    up.second = down.second+1;
                } else if (down.second+1 == up.second && nums[i] > up.first) {
                    up.first = nums[i];
                }
            }
            if (nums[i] < up.first) {
                if (up.second+1 > down.second) {
                    down.first = nums[i];
                    down.second = up.second+1;
                } else if (up.second+1 == down.second && nums[i] < down.first) {
                    down.first = nums[i];
                }
            }
        }
        return max(up.second, down.second);
#else  // O(N^2)
        vector<int> up(nums.size(), 1), down(nums.size(), 1);
        int ans = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    up[i] = max(up[i], down[j]+1);
                } else if (nums[i] < nums[j]) {
                    down[i] = max(down[i], up[j]+1);
                }
            }
            ans = max({ans, up[i], down[i]});
        }
        return ans;
#endif
    }
};