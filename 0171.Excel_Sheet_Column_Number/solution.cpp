class Solution {
public:
    int titleToNumber(string s) {
        int ret_val = 0;
        for (auto it : s) {
            ret_val = (ret_val * 26) + (it - 'A' + 1);
        }
        return ret_val;
    }
};