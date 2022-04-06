class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjaceny_list(numCourses);
        vector<int> ref(numCourses, 0);
        queue<int> available_courses;
        vector<int> result;
        for (auto & c : prerequisites) {
            adjaceny_list[c[1]].push_back(c[0]);
            ref[c[0]]++;
        }
        for (int i = 0; i < ref.size(); i++) {
            if (ref[i] == 0) {
                result.push_back(i);
                available_courses.push(i);
            }
        }
        while (!available_courses.empty()) {
            int course = available_courses.front();
            available_courses.pop();
            for (auto c : adjaceny_list[course]) {
                ref[c]--;
                if (ref[c] == 0) {
                    result.push_back(c);
                    available_courses.push(c);
                }
            }
        }
        if (result.size() != numCourses)
            return {};
        return result;
    }
};