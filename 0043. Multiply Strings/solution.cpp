class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans_v(400, 0);
        int start = 0;
        // get multiply
        for (int i = num1.size()-1; i >= 0; i--) {
            for (int j = num2.size()-1; j >= 0; j--) {
                int result = (num1[i] - '0') * (num2[j] - '0');
                int idx = start + num2.size() - j - 1;
                ans_v[idx] += result % 10;
                ans_v[idx+1] += result / 10;
            }
            start++;
        }
        // add overflow
        int overflow = 0;
        for (int i = 0; i < ans_v.size(); i++) {
            ans_v[i] += overflow;
            overflow = ans_v[i] / 10;
            ans_v[i] %= 10;
        }
        // output stirng
        string ans = "";
        for (int i = ans_v.size() - 1; i >= 0; i--) {
            if (ans == "" && ans_v[i] == 0) continue;
            ans += ans_v[i] + '0';
        }
        return (ans == "")? "0":ans;
    }
};