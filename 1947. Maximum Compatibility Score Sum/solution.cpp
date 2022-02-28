class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> permutation;
        for (int i = 0; i < students.size(); i++)
            permutation.push_back(i);
        int max_score = 0;
        do {
            int curr_score = 0;
            for (int m = 0; m < mentors.size(); m++) {
                for (int n = 0; n < mentors[m].size(); n++) {
                    curr_score += (students[permutation[m]][n] == mentors[m][n])?1:0;
                }
            }
            max_score = max(curr_score, max_score);
        } while (next_permutation(permutation.begin(), permutation.end()));
        return max_score;
    }
#if 0 // Need more complexity
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int student_num = students.size();
        int mentor_num = mentors.size();
        int question_num = students[0].size();
        vector<vector<int>> map_table(student_num, vector<int>(mentor_num, 0));
        // create map_table
        for (int s = 0; s < student_num; s++) {
            for (int m = 0; m < mentor_num; m++) {
                for (int n = 0; n < question_num; n++) {
                    map_table[s][m] += (mentors[m][n] == students[s][n])?1:0;
                }
            }
        }
        // calculate maximum mapping
        vector<bool> already_matched(mentor_num, false);
        get_max_mapping(map_table, already_matched);
        return max_score;
    }
    void get_max_mapping(vector<vector<int>> & map_table, vector<bool> & already_matched) {
        if (permutation.size() == already_matched.size()) {
            int current_score = 0;
            for (int i = 0; i < permutation.size(); i++) {
                current_score += map_table[i][permutation[i]];
            }
            max_score = max(current_score, max_score);
        } else {
            for (int i = 0; i < already_matched.size(); i++) {
                if (!already_matched[i]) {
                    already_matched[i] = true;
                    permutation.push_back(i);
                    get_max_mapping(map_table, already_matched);
                    permutation.pop_back();
                    already_matched[i] = false;
                }
            }
        }
    }
private:
    int max_score = 0;
    vector<int> permutation;
#endif
};