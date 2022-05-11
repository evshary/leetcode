class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> s;
        for (auto n : num) {
            while (k != 0 && !s.empty() && n < s.back()) {
                s.pop_back();
                k--;
            }
            s.push_back(n);
        }
        string ans;
        while (s.size() > k) {
            if (!(ans == "" && s.front() == '0'))
                ans += s.front();
            s.pop_front();
        }
        return (ans == "")?"0":ans;
    }
};
