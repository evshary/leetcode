class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int interval_begin = intervals[0][0];
        int interval_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= interval_end) {
                interval_begin = min(interval_begin, intervals[i][0]);
                interval_end = max(interval_end, intervals[i][1]);
            } else {
                result.push_back({interval_begin, interval_end});
                interval_begin = intervals[i][0];
                interval_end = intervals[i][1];
            }
        }
        result.push_back({interval_begin, interval_end});
        return result;
    }
};