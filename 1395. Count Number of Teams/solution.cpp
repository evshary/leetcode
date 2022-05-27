class Solution {
public:
    int numTeams(vector<int>& rating) {
#if 1  // space O(1)
        int ans = 0;
        for (int i = 0; i < rating.size()-1; i++) {
            int left_small = 0, left_big = 0, right_small = 0, right_big = 0;
            for (int j = 0; j < rating.size(); j++) {
                if (rating[i] > rating[j]) {
                    if (i > j) left_small++;
                    else right_small++;
                }
                if (rating[i] < rating[j]) {
                    if (i > j) left_big++;
                    else right_big++;
                }
            }
            ans += left_small * right_big + left_big * right_small;
        }
        return ans;
#else  // space O(N)
        vector<int> max_cnt(rating.size(), 0), min_cnt(rating.size(), 0);
        int ans = 0;
        for (int i = 1; i < rating.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (rating[i] > rating[j]) {
                    min_cnt[i]++;
                    if (min_cnt[j] >= 1) ans += min_cnt[j];
                } else if (rating[i] < rating[j]) {
                    max_cnt[i]++;
                    if (max_cnt[j] >= 1) ans += max_cnt[j];
                }
            }
        }
        return ans;
#endif
    }
};