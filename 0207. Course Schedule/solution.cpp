class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);
        vector<bool> pass(numCourses, true);
        int last_pass = 0, cur_pass = numCourses;
        for (auto& v : prerequisites) {
            courses[v[0]].push_back(v[1]);
            if (courses[v[0]].size() == 1) {
                pass[v[0]] = false;
                cur_pass--;
            }
        }
        while (last_pass != cur_pass) {
            last_pass = cur_pass;
            for (int i = 0; i < numCourses; i++) {
                if (pass[i]) continue;
                bool pass_or_not = true;
                for (auto n : courses[i]) {
                    if (pass[n] == false) {
                        pass_or_not = false;
                        break;
                    }
                }
                if (pass_or_not) {
                    pass[i] = true;
                    cur_pass++;
                }
            }
        }
        return cur_pass == numCourses;
    }
};