class Solution {
public:
    static bool compare(string &a, string &b) {
        return a.length() > b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> hash;
        int result = 1;
        for (auto word : words) {
            if (hash.find(word) == hash.end()) hash[word] = 1;
            for (int i = 0; i < word.length(); i++) {
                string cmp_str = word.substr(0, i) + word.substr(i+1);
                if (hash.find(cmp_str) == hash.end()) {
                    hash[cmp_str] = hash[word] + 1;
                } else {
                    hash[cmp_str] = max(hash[cmp_str], hash[word] + 1);
                }
            }
            result = max(result, hash[word]);
        }
        return result;
    }
};