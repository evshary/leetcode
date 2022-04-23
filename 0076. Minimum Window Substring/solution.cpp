class Solution {
public:
    string minWindow(string s, string t) {
        // create hash for t
        unordered_map<char,int> board, needs;
        for (auto c : t) {
            needs[c]++;
        }
        int match = 0;
        int result_start, result_len = INT_MAX;
        int left = 0, right = 0;
        // sliding window
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (needs.count(c)) {
                board[c]++;
                if (needs[c] == board[c])
                    match++;
            }
            while (match == needs.size()) {
                if (result_len > right - left) {
                    result_start = left;
                    result_len = right - left;
                }
                char old_c = s[left];
                left++;
                if (needs.count(old_c)) {
                    board[old_c]--;
                    if (needs[old_c] > board[old_c])
                        match--;
                }
            }
        }
        return (result_len == INT_MAX)? "":s.substr(result_start, result_len);
    }
};