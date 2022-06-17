class Solution {
private:
    bool isPalindrome(string s) {
        int begin = 0, end = s.size()-1;
        while (begin <= end) {
            if (s[begin] != s[end]) return false;
            begin++, end--;
        }
        return true;
    }
    void traverse(vector<vector<string>>& result, vector<string> combination, string& s, int idx) {
        if (idx == s.size()) {
            result.push_back(combination);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            string split_str = s.substr(idx, i-idx+1);
            if (isPalindrome(split_str)) {
                combination.push_back(split_str);
                traverse(result, combination, s, i+1);
                combination.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        traverse(result, vector<string>{}, s, 0);
        return result;
    }
};