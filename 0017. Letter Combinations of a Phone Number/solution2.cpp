class Solution {
private:
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void traverse(vector<string>& result, string s, string& digits, int idx, int k) {
        if (k == 0) {
            result.push_back(s);
            return;
        }
        for (auto c : map[digits[idx]-'0']) {
            traverse(result, s+c, digits, idx+1, k-1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) return result;
        traverse(result, "", digits, 0, digits.size());
        return result;
    }
};