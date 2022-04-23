class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int alphabets[26] = {0};
        for (auto c : s1) {
            alphabets[c-'a']++;
        }
        int left = 0, right = 0;
        while (right < s2.size()) {
            char c = s2[right];
            right++;
            alphabets[c-'a']--;
            while (alphabets[c-'a'] < 0) {
                char old_c = s2[left];
                left++;
                alphabets[old_c-'a']++;
            }
            if (right - left == s1.size()) {
                return true;
            }
        }
        return false;
    }
};