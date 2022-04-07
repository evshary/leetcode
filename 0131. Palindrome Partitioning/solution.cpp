class Solution {
private:
    vector<vector<string>> result;
    bool isPalindrome(string & s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void getPalindrome(string & s, int index, vector<string> & partition) {
        if (index == s.size()) {
            result.push_back(partition);
            return;
        }
        for (int len = 1; len <= s.size() - index; len++) {
            string sub_string = s.substr(index, len);
            if (isPalindrome(sub_string)) {
                partition.push_back(sub_string);
                getPalindrome(s, index+len, partition);
                partition.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        getPalindrome(s, 0, partition);
        return result;
    }
};