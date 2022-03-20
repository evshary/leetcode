class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_table(26, -1);
        for (int i = 0; i < s.size(); i++) {
            last_table[s[i]-'a'] = i;
        }
        vector<int> answer;
        int cur_len = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last_table[s[i]-'a']);
            cur_len++;
            if (i == end) {
                answer.push_back(cur_len);
                cur_len = 0;
            }
        }
        return answer;
    }
};
