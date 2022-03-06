class Solution {
public:
    int knightDialer(int n) {
        vector<vector<unsigned long long>> mapping_tables = {
            {4,6}, {6,8}, {7,9}, {4,8}, {3,9,0}, {}, {1,7,0}, {2,6}, {1,3}, {4,2}
        };
        vector<unsigned long long> result_array(10, 1);
        for (int i = 1; i < n; i++) {
            vector<unsigned long long> next_result_array(10, 0);
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < mapping_tables[j].size(); k++) {
                    next_result_array[j] += result_array[mapping_tables[j][k]];
                }
                next_result_array[j] %= 1000000007;
            }
            result_array = next_result_array;
        }
        unsigned long long answer = 0;
        for (int i = 0; i < 10; i++) {
            answer += result_array[i];
        }
        return answer % 1000000007;
    }
};