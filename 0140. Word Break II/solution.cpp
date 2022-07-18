class Solution {
private:
	void traverse(vector<string>& result, string s, int idx, string cur_s, unordered_set<string>& dict) {
		if (idx == s.size()) {
			result.push_back(cur_s);
			return;
		}
		if (idx != 0) cur_s += " ";
		string new_word = "";
		for (int i = idx; i < s.size(); i++) {
			new_word.push_back(s[i]);
			if (dict.count(new_word)) {
				traverse(result, s, i+1, cur_s+new_word, dict);
			}
		}
	}
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> result;
        traverse(result, s, 0, "", dict);
        return result;
    }
};