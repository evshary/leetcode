#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<char> map(26, 0);
        vector<char> cmp_map(26, 0);
        vector<int> result;
        bool match = false;
        int start = 0;
        for (int i = 0; i < p.length(); i++) {
            map[p[i]-'a'] += 1;
        }
        for (int i = 0; i < s.length() && i < p.length()-1; i++)
            cmp_map[s[i]-'a']++;
        for (int i = p.length()-1; i < s.length(); i++) {
            cmp_map[s[i]-'a']++;
            match = true;
            for (int j = 0; j < 26; j++) {
                if (cmp_map[j] != map[j])
                    match = false;
            }
            if (match)
                result.push_back(start);
            cmp_map[s[start]-'a']--;
            start++;
        }
        return result;
    }
};

int main() {
    vector<pair<string,string>> problems{{"cbaebabacd", "abc"}, {"abab", "ab"}, {"aaaaaaaaaa", "aaaaaaaaaaaaa"}};
    Solution s;
    for (auto p : problems) {
        vector<int> result = s.findAnagrams(p.first, p.second);
        for (auto num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}