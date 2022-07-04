class Solution {
private:
	bool isAlphanumeric(char c) {
	    if (c >= '0' && c <= '9') return true;
	    if (c >= 'a' && c <= 'z') return true;
	    if (c >= 'A' && c <= 'Z') return true;
	    return false;
	}
	char convert(char c) {
		if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
		return c;
	}
public:
    bool isPalindrome(string s) {
        int begin = 0, end = s.size()-1;
        while (begin <= end) {
            if (!isAlphanumeric(s[begin])) {
            	begin++;
            } else if (!isAlphanumeric(s[end])) {
            	end--;
            } else {
            	if (convert(s[begin]) != convert(s[end])) return false;
                begin++;
                end--;
            }
        }
        return true;
    }
};