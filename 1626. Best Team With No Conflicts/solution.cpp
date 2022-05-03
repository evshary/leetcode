class Solution {
private:
    static bool compare(pair<int,int>& p1, pair<int,int>& p2) {
        if (p1.second > p2.second) {
            return true;
        } else if (p1.second == p2.second) {
            return (p1.first > p2.first)? true:false;
        } else {
            return false;
        }
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> p_vector;
        for (int i = 0; i < scores.size(); i++) {
            p_vector.push_back({scores[i], ages[i]});
        }
        sort(p_vector.begin(), p_vector.end(), compare);
        vector<int> dp(p_vector.size(), 0);
        int max_result = 0;
        for (int i = 0; i < p_vector.size(); i++) {
            dp[i] = p_vector[i].first;
            for (int j = 0; j < i; j++) {
                if (p_vector[j].first >= p_vector[i].first) {
                    dp[i] = max(dp[i], dp[j] + p_vector[i].first);
                }
            }
            max_result = max(max_result, dp[i]);
        }
        return max_result;
    }
};