class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hash;
        for (auto c : s) {
        	hash[c]++;
        }
        int longest_len = 0;
        bool isOdd = false;
        for (auto h : hash) {
        	if (h.second % 2 != 0) {
        	    h.second--;
        	    isOdd = true;
        	}
        	longest_len += h.second;
        }
        if (isOdd) longest_len += 1;
        return longest_len;
    }
};