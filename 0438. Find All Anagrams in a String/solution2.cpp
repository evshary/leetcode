class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> hash_p;
        int left = 0, right = 0;
        vector<int> result;
        for (auto c : p) {
            hash_p[c] += 1;
        }
        while (right < s.size()) {
            char c = s[right];
            right++;
            hash_p[c]--;
            while (hash_p[c] < 0) {
                char old_c = s[left];
                left++;
                hash_p[old_c]++;
            }
            if (right - left == p.size()) {
                result.push_back(left);
            }
        }
        return result;
    }
};