class Solution {
private:
	typedef struct {
		int start;
		int end;
		int profit;
	} tasks;
	static bool compare(tasks &t1, tasks &t2) {
		return t1.end <= t2.end;
	}
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tasks> t;
        for (int i = 0; i < startTime.size(); i++) {
        	t.push_back({.start=startTime[i], .end=endTime[i], .profit=profit[i]});
        }
        sort(t.begin(), t.end(), compare);
        vector<int> dp(t.size());
        dp[0] = t[0].profit;
        for (int i = 1; i < dp.size(); i++) {
        	int last_max_profit = 0;
        	for (int j = i - 1; j >= 0; j--) {
        		if (t[j].end <= t[i].start) {
        			last_max_profit = dp[j];
        			break;
        		}
        	}
        	dp[i] = max(dp[i-1], last_max_profit + t[i].profit);
        }
        return dp.back();
    }
};