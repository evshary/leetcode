class Solution {
public:
    static bool compare(vector<int> & a, vector<int> & b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int arrow_num = 0;
        for (int i = 0; i < points.size(); ) {
            int balloon = i;
            while (i < points.size() && points[i][0] <= points[balloon][1]) {
                i++;
            }
            arrow_num++;
        }
        return arrow_num;
    }
};