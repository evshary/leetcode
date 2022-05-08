class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int best_sight = values[0] - 1;
        for (int i = 1; i < values.size(); i++) {
            ans = max(ans, best_sight+values[i]);
            best_sight = max(best_sight, values[i]) - 1;
        }
        return ans;
    }
};