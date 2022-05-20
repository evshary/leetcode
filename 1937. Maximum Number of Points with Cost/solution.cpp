#if 1
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> dp(n);
        for (int c = 0; c < n; c++) {
            dp[c] = points[0][c];
        }
        // dp[r][c2] = max(dp[r][c2] + dp[r][c1] + abc(c2-c1))
        // can become
        // dp[r][c2] = max(dp[r][c2] + dp[r][c1] + c2-c1) if c2 > c1
        //           = max(dp[r][c2] + c2 + dp[r][c1] - c1) if c2 > c1
        // dp[r][c2] = max(dp[r][c2] + dp[r][c1] + c1-c2) if c1 > c2
        //           = max(dp[r][c2] - c2 + dp[r][c1] + c1) if c1 > c2
        // Get the max of dp[r][c1] - c1 and dp[r][c1] + c1 first
        // Create left and right dp
        // left[c]: for index c, the max value in the left of dp[r][c] + c
        // right[c]: for index c, the max value in the right of dp[r][c] - c
        // dp[r][c] = dp[r][c] + max(left[c] - c, right[c] + c)
        for (int r = 1; r < m; r++) {
            vector<long long> left(n);
            vector<long long> right(n);
            left[0] = dp[0] + 0;
            for (int c = 1; c < n; c++) {
                left[c] = max(left[c-1], dp[c] + c);
            }
            right[n-1] = dp[n-1] - (n-1);
            for (int c = n-2; c >= 0; c--) {
                right[c] = max(right[c+1], dp[c] - c);
            }
            for (int c = 0; c < n; c++) {
                dp[c] = points[r][c] + max(left[c] - c, right[c] + c);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
#else
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        for (int r = 1; r < points.size(); r++) {
            for (int i = 0; i < points[r].size(); i++) {
                int max_num = INT_MIN;
                for (int j = 0; j < points[r-1].size(); j++) {
                    max_num = max(max_num, points[r][i] + points[r-1][j] - abs(i-j));
                }
                points[r][i] = max_num;
            }
        }
        int ans = INT_MIN;
        for (int c = 0; c < points[0].size(); c++) {
            ans = max(ans, points[points.size()-1][c]);
        }
        return ans;
    }
};
#endif