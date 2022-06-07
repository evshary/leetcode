class Solution {
public:
#if 1 // O(N)
    long long countVowels(string word) {
        long long ans = 0;
        long long count = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                count += (i+1);
            }
            ans += count;
        }
        return ans;
    }
#else // brute force O(N^2)
    long long countVowels(string word) {
        long long ans = 0;
        for (int start = 0; start < word.size(); start++) {
            int count = 0;
            for (int end = start; end < word.size(); end++) {
                if (word[end] == 'a' || word[end] == 'e' || word[end] == 'i' || word[end] == 'o' || word[end] == 'u') {
                    count++;
                }
                ans += count;
            }
        }
        return ans;
    }
#endif
};
