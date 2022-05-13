#if 1 // simplify
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int idx = 0;
        while (idx < intervals.size() && intervals[idx][1] < newInterval[0]) {
            ans.push_back(intervals[idx]);
            idx++;
        }
        while (idx < intervals.size() && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }
        ans.push_back(newInterval);
        while (idx < intervals.size()) {
            ans.push_back(intervals[idx]);
            idx++;
        }
        return ans;
    }
};
#else
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<int> overlapped;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] >= newInterval[0] && newInterval[1] >= intervals[i][0]) {
                overlapped.push_back(i);
            }
        }
        if (overlapped.size() != 0) {
            vector<int> overlapped_interval{0, 0};
            overlapped_interval[0] = min(newInterval[0], intervals[overlapped.front()][0]);
            overlapped_interval[1] = max(newInterval[1], intervals[overlapped.back()][1]);
            for (int i = 0; i < overlapped.front(); i++) {
                ans.push_back(intervals[i]);
            }
            ans.push_back(overlapped_interval);
            for (int i = overlapped.back()+1; i < intervals.size(); i++) {
                ans.push_back(intervals[i]);
            }
        } else {
            bool not_insert = true;
            for (int i = 0; i < intervals.size(); i++) {
                if (not_insert && newInterval[0] < intervals[i][0]) {
                    ans.push_back(newInterval);
                    not_insert = false;
                }
                ans.push_back(intervals[i]);
            }
            if (not_insert) {
                ans.push_back(newInterval);
            }
        }
        return ans;
    }
};
#endif