class Solution {
    int possible_seq = 0;
    void putChar(vector<int>& count, int remain_len) {
        possible_seq++;
        if (remain_len == 0) return;
        for (int i = 0; i < count.size(); i++) {
            if (count[i] == 0) continue;
            count[i]--;
            putChar(count, remain_len-1);
            count[i]++;
        }
        return;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> count(26, 0);
        for (auto s : tiles) {
            count[s-'A']++;
        }
        putChar(count, tiles.size());
        return possible_seq-1; // do not count empty string
    }
};