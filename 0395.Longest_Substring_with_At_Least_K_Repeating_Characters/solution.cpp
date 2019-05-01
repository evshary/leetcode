#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstring_r(s, 0, s.size(), k);
    }
private:
    int longestSubstring_r(string &s, int left, int right, int k) {
        vector<int> counter(26, 0);
        int result = 0;
        /* Count the occurance */
        for (int i = left; i < right; i++) counter[s[i]-'a']++;
        /* End condition */
        for (int i = 0; i < 26; i++) {
            if (counter[i] != 0 && counter[i] < k)
                break;
            if (i == 25) return right - left;
        }
        /* Divide and Conquer */
        for (int i = left, j; i < right; i = j) {
            while(i != right && counter[s[i]-'a'] < k) i++;
            j = i;
            while(j != right && counter[s[j]-'a'] >= k) j++;
            if (i + k <= j)
                result = max(result, longestSubstring_r(s, i, j, k));
        }
        return result;
    }
};

int main() {
    vector<pair<string,int>> problems{make_pair("aaabb", 3), make_pair("ababbc",2)};
    Solution solution;
    for (auto p : problems) {
        cout << p.first << " " << p.second << ": " << solution.longestSubstring(p.first, p.second) << endl;
    }
    return 0;
}