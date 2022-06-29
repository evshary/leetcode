#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> maps;
        for (int i = 0; i < s.size(); i++) {
            if (maps.find(s[i]) != maps.end())
                maps[s[i]] += 1;
            else
                maps[s[i]] = 1;
        }
        for (int i = 0; i < t.size(); i++) {
            if (maps.find(t[i]) == maps.end())
                return false;
            if (maps[t[i]] == 1)
                maps.erase(t[i]);
            else
                maps[t[i]] -= 1;
        }
        if (maps.empty())
            return true;
        else
            return false;
    }
};

int main() {
    Solution solution;
#if 0
    string s("anagram");
    string t("nagaram");
#elif 1
    string s("rat");
    string t("car");
#endif
    if (solution.isAnagram(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}