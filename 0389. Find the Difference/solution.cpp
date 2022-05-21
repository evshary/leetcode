class Solution {
public:
    char findTheDifference(string s, string t) {
#if 1 // fastest
        char ch = 0;
        for (auto c : s) ch ^= c;
        for (auto c : t) ch ^= c;
        return ch;
#elif 0  // faster
        int ch[26] = {0};
        for (auto c : s) ch[c-'a']++;
        for (auto c : t) {
            if (ch[c-'a'] == 0) return c;
            ch[c-'a']--;
        }
        return 0; // should not be here
#else
        unordered_map<char, int> hash;
        for (auto c : s) {
            hash[c]++;
        }
        for (auto c : t) {
            if (hash[c] == 0) return c;
            hash[c]--;
        }
        return 0; // should not be here
#endif
    }
};