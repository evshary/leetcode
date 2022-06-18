class Solution {
public:
    int jump(vector<int>& nums) {
#if 1
        int jump_cnt = 0;
        int cur_pos = 0, next_pos = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            next_pos = max(next_pos, i + nums[i]);
            if (i == cur_pos) {
                cur_pos = next_pos;
                jump_cnt++;
                if (cur_pos >= nums.size()-1) break;
            }
        }
        return jump_cnt;
#else
        int jump_cnt = 0;
        int cur_pos = 0;
        int next_pos = 0;
        while (cur_pos < nums.size() - 1) {
            for (int i = 1; i <= nums[cur_pos]; i++) {
                if (cur_pos + i >= nums.size() - 1) {
                    next_pos = cur_pos + i;
                    break;
                }
                if (cur_pos + i + nums[cur_pos+i] >= next_pos + nums[next_pos]) {
                    next_pos = cur_pos + i;
                }
            }
            cur_pos = next_pos;
            jump_cnt++;
        }
        return jump_cnt;
#endif
    }
};