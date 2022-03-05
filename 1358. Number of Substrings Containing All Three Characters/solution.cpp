class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int count[3] = {0, 0, 0};
        int j = -1;
        for (int i = 0; i < s.size() && j < (int)s.size(); i++) {
            if (i > 0)
                count[s[i-1]-'a']--;
            while (count[0] == 0 || count[1] == 0 || count[2] == 0) {
                j++;
                if (j >= s.size())
                    break;
                count[s[j]-'a']++;
            }
            res += s.size() - j;
        }
        return res;
#if 0 // time: O(N) space: O(N)
        int res = 0;
        vector<int> v_ch[3];
        for (int i = 0; i < s.size(); i++) {
            v_ch[s[i]-'a'].push_back(i);
        }
        int idx[3] = {0, 0, 0};
        while (idx[0] != v_ch[0].size() && idx[1] != v_ch[1].size() && idx[2] != v_ch[2].size()) {
            vector<pair<int, int>> v_ch_pairs;
            for (int i = 0; i < 3; i++) {
                v_ch_pairs.push_back(make_pair(v_ch[i][idx[i]], i));
            }
            sort(v_ch_pairs.begin(), v_ch_pairs.end());
            int max_idx = v_ch_pairs[2].first;
            res += s.size() - max_idx;
            int min_ch_idx = v_ch_pairs[0].second;
            idx[min_ch_idx]++;
        }
        return res;
#endif
    }
};