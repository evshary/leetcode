class Solution {
    vector<string> answer;
    vector<vector<string>> mapping{{}, 
                                   {},
                                   {"a", "b", "c"},      // 2
                                   {"d", "e", "f"},      // 3
                                   {"g", "h", "i"},
                                   {"j", "k", "l"},      // 5
                                   {"m", "n", "o"},
                                   {"p", "q", "r", "s"}, // 7
                                   {"t", "u", "v"},
                                   {"w", "x", "y", "z"}  // 9
                                   };
    void recursive(string & digits, int depth, string letters) {
        if (depth == digits.size()) {
            // end condition
            answer.push_back(letters);
        } else {
            for (int i = 0; i < mapping[digits[depth]-'0'].size(); i++) {
                recursive(digits, depth+1, letters+mapping[digits[depth]-'0'][i]);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits != "")
            recursive(digits, 0, "");
        return answer;
    }
};