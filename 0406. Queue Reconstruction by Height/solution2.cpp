#if 1
class Solution {
private:
    static bool compare(vector<int>& p1, vector<int>& p2) {
        if (p1[0] == p2[0]) {
            return p1[1] < p2[1];
        }
        return p1[0] > p2[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> result;
        for (auto & p : people) {
            result.insert(result.begin() + p[1], p);
        }
        return result;
    }
};
#else
class Solution {
private:
    static bool compare(vector<int>& p1, vector<int>& p2) {
        if (p1[1] == p2[1]) {
            return p1[0] < p2[0];
        }
        return p1[1] < p2[1];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> result;
        for (auto& p : people) {
            int cmp_num = 0;
            int idx = 0;
            while (idx < result.size()) {
                if (result[idx][0] >= p[0]) cmp_num++;
                if (cmp_num > p[1]) break;
                idx++;
            }
            result.insert(result.begin()+idx, p);
        }
        return result;
    }
};
#endif