class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // TC: O(NlogN), SC: O(N)
        vector<vector<int>> new_range;
        for (int i = 0; i < ranges.size(); i++) {
            new_range.push_back({max(0, i-ranges[i]), i + ranges[i]});
        }
        sort(new_range.begin(), new_range.end());
        int begin = 0, end = 0;
        int total_cnt = 1;
        for (int i = 0; i < new_range.size(); i++) {
            if (new_range[i][0] <= begin) {
                end = max(end, new_range[i][1]);
            } else {
                if (new_range[i][0] > end) return -1;
                if (new_range[i][1] <= end) continue;
                begin = end;
                end = new_range[i][1];
                total_cnt++;
            }
            if (end >= n) break;
        }
        return total_cnt;
    }
};