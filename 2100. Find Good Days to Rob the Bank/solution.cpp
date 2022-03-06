class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> result;
        int security_size = security.size();
        vector<int> left(security_size, 0);
        vector<int> right(security_size, 0);
        
        for (int i = 1; i < security_size; i++) {
            if (security[i] <= security[i-1]) {
                left[i] = left[i-1] + 1;
            } else {
                left[i] = 0;
            }
        }
        
        for (int i = security_size-2; i >= 0; i--) {
            if (security[i] <= security[i+1]) {
                right[i] = right[i+1] + 1;
            } else {
                right[i] = 0;
            }
        }
        
        for (int i = 0; i < security_size; i++) {
            if (left[i] >= time && right[i] >= time) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};