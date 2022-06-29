#if 1
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string tmp = s + s;
        tmp = tmp.substr(1, tmp.size()-2); // remove the first and the last char
        return tmp.find(s) != string::npos;        
    }
};
#else
class Solution {
private:
    void getNext(int *next, string &s) {
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
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getNext(next, s);
        if (next[s.size()-1] != -1 && s.size() % (s.size() - (next[s.size()-1] + 1)) == 0) {
            return true;
        }
        return false;
    }
};
#endif
