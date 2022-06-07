class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> head(s.size()+1), end(s.size()+1);
        for (int i = 0; i < s.size(); i++) {
            head[i+1] = head[i] + ((s[i] == '1')? 1:0);
        }
        for (int i = s.size()-1; i >= 0; i--) {
            end[i] = end[i+1] + ((s[i] == '0')? 1:0);
        }
        int res = INT_MAX;
        for (int i = 0; i < head.size(); i++) {
            res = min(res, head[i] + end[i]);
        }
        return res;
    }
};
