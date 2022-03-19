class Solution {
public:
    static bool compare(vector<int> & a, vector<int> & b) {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int overlap = 0;
        int end = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[end][1]) {
                overlap++;
            } else {
                end = i;
            }
        }
        return overlap;
    }
};