class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> S(5, 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 4; j++) {
                S[j+1] += S[j];
            }
        }
        return S[4];
    }
};