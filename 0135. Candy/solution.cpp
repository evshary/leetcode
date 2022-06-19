class Solution {
public:
    int candy(vector<int>& ratings) {
        // TC:O(N), SC:O(N)
        vector<int> front(ratings.size(), 1);
        vector<int> back(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) front[i] = front[i-1] + 1;
        }
        for (int i = ratings.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) back[i] = back[i+1] + 1;
        }
        int total_candy = 0;
        for (int i = 0; i < ratings.size(); i++) {
            total_candy += max(front[i], back[i]);
        }
        return total_candy;
    }
};