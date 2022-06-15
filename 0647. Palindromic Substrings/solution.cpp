#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int ret_count = 0;
        queue<pair<int,int>> q, tmp_q;
        for (int i = 0; i < s.length(); i++) {
            tmp_q.push(make_pair(i,i));
            ret_count++;
            while (!q.empty()) {
                pair<int,int> p = q.front();
                if (p.first == p.second && s[p.first] == s[i]) {
                    tmp_q.push(make_pair(p.first,i));
                    ret_count++;
                }
                if (p.first > 0 && s[p.first-1] == s[i]) {
                    tmp_q.push(make_pair(p.first-1,i));
                    ret_count++;
                }
                q.pop();
            }
            swap(q, tmp_q);
        }
        return ret_count;
    }
};

int main() {
    vector<string> problems{"abc","aaa","ababa"};
    Solution s;
    for (auto p : problems) {
        cout << p << ":";
        cout << s.countSubstrings(p) << endl;
    }
    return 0;
}