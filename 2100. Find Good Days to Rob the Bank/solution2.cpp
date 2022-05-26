class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> left(security.size(), 1), right(security.size(), 1);
        for (int i = 1; i < security.size(); i++) {
            if (security[i-1] >= security[i]) {
                left[i] += left[i-1];
            }
        }
        for (int i = security.size()-2; i >= 0; i--) {
            if (security[i] <= security[i+1]) {
                right[i] += right[i+1];
            }
        }
        vector<int> ans;
        for (int i = 0; i < security.size(); i++) {
            if (left[i] > time && right[i] > time) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};