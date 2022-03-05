class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // simpler solution
        int previous_cnt = 0;
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                res = max(res, previous_cnt + cnt);
                previous_cnt = cnt;
                cnt = 0;
            }
        }
        res = max(res, previous_cnt + cnt);
        return (res == nums.size())?res-1:res;
#if 0
        vector<int> seq;
        int longest_len = 0;
        int tmp_seq_len = 0;
        // generate seq
        for (auto n : nums) {
            if (n == 0) {
                if (tmp_seq_len != 0) {
                    seq.push_back(tmp_seq_len);
                    tmp_seq_len = 0;
                }
                seq.push_back(0);
            } else {
                tmp_seq_len++;
            }
        }
        if (tmp_seq_len != 0)
            seq.push_back(tmp_seq_len);
        // Exception: while there are only 1 in nums
        if (seq.size() == 1)
            return tmp_seq_len - 1;
        // Find the longest_len
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == 0) {
                longest_len = max(longest_len, ((i==0)?0:seq[i-1]) + ((i==seq.size()-1)?0:seq[i+1]));
            }
        }
        return longest_len;
#endif
    }
};