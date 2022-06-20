class Solution {
private:
    void reverse(string & s, int begin, int end) {
        while (begin < end) {
            swap(s[begin++], s[end--]);
        }
    }
public:
    string reverseWords(string s) {
        // remove space
        int slow_ptr = 0, fast_ptr = 0;
        while (s[fast_ptr] == ' ') fast_ptr++;
        while (fast_ptr < s.size()) {
            if (s[fast_ptr] != ' ') {
                s[slow_ptr++] = s[fast_ptr++];
            } else {
                while (fast_ptr < s.size() && s[fast_ptr] == ' ') fast_ptr++;
                if (fast_ptr < s.size()) {
                    s[slow_ptr++] = ' ';
                }
            }
        }
        s.resize(slow_ptr);
        // reverse whole string
        reverse(s, 0, s.size()-1);
        // reverse each word
        slow_ptr = fast_ptr = 0;
        while (fast_ptr < s.size()) {
            while (fast_ptr < s.size() && s[fast_ptr] != ' ') fast_ptr++;
            reverse(s, slow_ptr, fast_ptr-1);
            slow_ptr = fast_ptr = fast_ptr + 1;
        }
        return s;
    }
};