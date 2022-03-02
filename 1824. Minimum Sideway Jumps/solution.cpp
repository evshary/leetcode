class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(n+1, vector<int>(4, 500001));
        dp[0][1] = dp[0][3] = 1;
        dp[0][2] = 0;
        for (int i = 1; i < n+1; i++) {
            // Go forward
            if (obstacles[i] != 1) dp[i][1] = dp[i-1][1];
            if (obstacles[i] != 2) dp[i][2] = dp[i-1][2];
            if (obstacles[i] != 3) dp[i][3] = dp[i-1][3];
            // Side jump
            if (obstacles[i] != 1) dp[i][1] = min(dp[i][1], min(dp[i][2], dp[i][3]) + 1);
            if (obstacles[i] != 2) dp[i][2] = min(dp[i][2], min(dp[i][1], dp[i][3]) + 1);
            if (obstacles[i] != 3) dp[i][3] = min(dp[i][3], min(dp[i][1], dp[i][2]) + 1);
        }
        return min(dp[n][1], min(dp[n][2], dp[n][3]));
    }
#if 0
    int minSideJumps(vector<int>& obstacles) {
        int cur_lane = 2;
        int pos = 0;
        int side_jump = 0;
        int n = obstacles.size() - 1;
        while (pos != n) {
            if (obstacles[pos] != cur_lane) {
                pos++;
            } else {
                vector<int> possible_pos(4, 0);
	            for (int i = 1; i <= 3; i++) {
	                if (i == cur_lane || obstacles[pos - 1] == i)
                        continue;
	                possible_pos[i] = pos;
	                while (possible_pos[i] != n && obstacles[possible_pos[i]] != i)
	                    possible_pos[i]++;
	            }
	            auto it = max_element(possible_pos.begin(), possible_pos.end());
	            cur_lane = it - possible_pos.begin();
	            pos = *it;
	            side_jump++;
            }
        }
        return side_jump;
    }
#endif
};