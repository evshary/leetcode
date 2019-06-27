#include <iostream>
#include <unordered_map>
using namespace std;

#if 1 // using const array is much better
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash1[256] = {0}, hash2[256] = {0};
        for (int i = 0 ; i < s.size(); i++) {
            if (hash1[s[i]] != hash2[t[i]]) return false;
            hash1[s[i]] = i+1;
            hash2[t[i]] = i+1;
        }
        return true;
    }
};
#else
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash1;
        unordered_map<char, char> hash2;
        for (int i = 0; i < s.size(); i++) {
            if (hash1[s[i]] == 0 && hash2[t[i]] == 0) {
                hash1[s[i]] = t[i];
                hash2[t[i]] = s[i];
            } else {
                if (hash1[s[i]] != t[i] || hash2[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};
#endif

int main() {
    string s = "paper";
    string t = "title";
    Solution sol;
    if (sol.isIsomorphic(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}