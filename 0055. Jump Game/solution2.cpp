class Solution {
public:
    bool canJump(vector<int>& nums) {
#if 1
        int cover = 0;
        for (int i = 0; i <= cover; i++) {
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size()-1) return true;
        }
        return false;
#else
        int cur_pos = 0;
        int next_pos = 0;
        while (cur_pos + nums[cur_pos] < nums.size() - 1) {
            if (nums[cur_pos] == 0) return false;
            for (int i = 1; i <= nums[cur_pos]; i++) {
                if (cur_pos + i + nums[cur_pos+i] >= next_pos + nums[next_pos]) {
                    next_pos = cur_pos + i;
                }
            }
            cur_pos = next_pos;
        }
        return true;
#endif
    }
};