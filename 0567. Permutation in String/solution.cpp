class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> alphabets(26, 0);
        // create s1 hash table
        for (auto c : s1) {
            alphabets[c-'a']++;
        }
        // use sliding window check whether there is end - start = s1.size()
        int start = 0, end = 0;
        while (end < s2.size()) {
            while (start < end && alphabets[s2[end]-'a'] <= 0) {
                alphabets[s2[start]-'a']++;
                start++;
            }
            if (alphabets[s2[end]-'a'] > 0) {
                alphabets[s2[end]-'a']--;
                end++;
            } else {
                start++;
                end++;
            }
            if (end - start == s1.size()) {
                return true;
            }
        }
        return false;
    }
};