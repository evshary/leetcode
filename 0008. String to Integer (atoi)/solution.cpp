class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        bool positive = true;
        if (s == "") return 0;
        while (s[idx] == ' ') idx++;
        if (s[idx] == '+') {
            positive = true;
            idx++;
        } else if (s[idx] == '-') {
        	positive = false;
        	idx++;
        }
        long result = 0;
        while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
        	result = result * 10 + (positive? (s[idx]-'0'):-(s[idx]-'0'));
            idx++;
            if (result >= INT_MAX) {
                result = INT_MAX;
                break;
            } else if (result <= INT_MIN) {
                result = INT_MIN;
                break;
            }
        }
        return (int)result;
    }
};