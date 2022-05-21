class Solution {
public:
    string pushDominoes(string dominoes) {
        char last_stat = 'L';
        int last_idx = -1;
        for (int i = 0; i <= dominoes.size(); i++) {
            char cur_stat = (i == dominoes.size())? 'R':dominoes[i];
            if (cur_stat != '.') {
                if (cur_stat == last_stat) {
                    for (int j = last_idx+1; j < i; j++) {
                        dominoes[j] = last_stat;
                    }
                } else if (cur_stat == 'L') {
                    int left = last_idx+1, right = i-1;
                    while (left < right) {
                        dominoes[left++] = 'R';
                        dominoes[right--] = 'L';
                    }
                }
                last_stat = cur_stat;
                last_idx = i;
            }
        }
        return dominoes;
    }
};