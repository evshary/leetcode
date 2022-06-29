#if 1
class Solution {
private:
    void getNext(int *next, string& s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j+1]) {
                j = next[j];
            }
            if (s[i] == s[j+1]) {
                j++;
            }
            next[i] = j;
        }
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            while (j >= 0 && haystack[i] != needle[j+1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j+1]) {
                j++;
            }
            if (j == needle.size()-1) {
                return i - (needle.size() - 1);
            }
        }
        return -1;
    }
};
#else
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); i++) {
            int cur_i = i, j = 0;
            while (cur_i < haystack.size() && j < needle.size() && haystack[cur_i] == needle[j]) {
                cur_i++;
                j++;
            }
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};
#endif