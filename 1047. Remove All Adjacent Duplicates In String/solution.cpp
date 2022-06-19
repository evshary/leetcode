class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> dq;
        for (auto c : s) {
            if (!dq.empty() && dq.back() == c) {
                dq.pop_back();
            } else {
                dq.push_back(c);
            }
        }
        string ans = "";
        while (!dq.empty()) {
            ans += dq.front();
            dq.pop_front();
        }
        return ans;
    }
};