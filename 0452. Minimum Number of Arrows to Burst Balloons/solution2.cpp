class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int arrow_num = 0;
        int total_balloon = points.size();
        int begin = 0, end = 0;
        while (total_balloon != 0) {
            int burst_balloon = 0;
            int right_bound = points[begin][1];
            while (end < points.size() && points[end][0] <= right_bound) {
                right_bound = min(right_bound, points[end][1]);
                burst_balloon++;
                end++;
            }
            total_balloon -= burst_balloon;
            arrow_num++;
            begin = end;
        }
        return arrow_num;
    }
};