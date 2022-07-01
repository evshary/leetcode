class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> ch_sets;
        for (auto c : s) {
            ch_sets.insert(c);
        }
        int max_length = INT_MIN;
        for (auto c : ch_sets) {
            int left = 0, right = 0;
            int used_k = 0;
            while (right < s.size()) {
                if (s[right] != c) {
                    used_k++;
                }
                right++;
                while (used_k > k) {
                    if (s[left] != c) {
                        used_k--;
                    }
                    left++;
                }
                max_length = max(max_length, right - left);
            }
        }
        return max_length;
    }
};