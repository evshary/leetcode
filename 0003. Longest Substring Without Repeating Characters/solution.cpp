class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int left = 0, right = 0;
        int max_len = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            hash[c]++;
            while (hash[c] > 1) {
                char old_c = s[left];
                left++;
                hash[old_c]--;
            }
            max_len = max(max_len, right-left);
        }
        return max_len;
    }
};