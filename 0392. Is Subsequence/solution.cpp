#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int> tables[26];
        for (int i = 0; i < t.size(); i++) {
            tables[t[i]-'a'].push_back(i);
        }
        int cur_pos = -1;
#if 0
        bool found;
        for (int i = 0; i < s.size(); i++) {
            found = false;
            for (auto pos : tables[s[i]-'a']) {
                if (pos > cur_pos) {
                    cur_pos = pos;
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
#else /* I found someone has more C++ like answer */
        for (int i = 0; i < s.size(); i++) {
            auto it = upper_bound(tables[s[i]-'a'].begin(), tables[s[i]-'a'].end(), cur_pos);
            if (it == tables[s[i]-'a'].end())
                return false;
            cur_pos = *it;
        }
#endif
        return true;
    }
};

int main() {
    Solution solution;
    string s = "abc";
    string t = "ahbgdc";
    cout << "s=" << s << ", t=" << t << endl;
    if (solution.isSubsequence(s,t))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}