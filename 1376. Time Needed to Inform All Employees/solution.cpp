class Solution {
private:
    vector<vector<int>> subordinates;
    int max_informTime = 0;
    void getInformTime(int id, int cur_informTime, vector<int>& informTime) {
        max_informTime = max(max_informTime, cur_informTime);
        for (auto s : subordinates[id]) {
            getInformTime(s, cur_informTime+informTime[id], informTime);
        }
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        subordinates.resize(n);
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] == -1) continue;
            subordinates[manager[i]].push_back(i);
        }
        getInformTime(headID, 0, informTime);
        return max_informTime;
    }
};