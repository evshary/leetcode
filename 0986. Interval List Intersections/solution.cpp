class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> answer;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            auto pair1 = firstList[i];
            auto pair2 = secondList[j];
            if (pair1[0] <= pair2[1] && pair2[0] <= pair1[1])
                answer.push_back({max(pair1[0], pair2[0]), min(pair1[1], pair2[1])});
            if (pair1[1] < pair2[1])
                i++;
            else
                j++;
        }
        return answer;
    }
};