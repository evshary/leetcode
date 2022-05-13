class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int ans = 0;
        int start = 0, end = 0;
        while (end < time) {
            int next_end = 0;
            for (auto & c : clips) {
                if (start <= c[0] && c[0] <= end) {
                    next_end = max(next_end, c[1]);
                }
            }
            if (next_end == 0) return -1;
            start = end + 1;
            end = next_end;
            ans++;
        }
        return ans;
    }
};