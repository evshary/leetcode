class Solution {
    vector<bool> visited;
    int visited_num = 0;
    void dfs(int cur_room, vector<vector<int>>& rooms) {
        if (visited[cur_room] == false) {
            visited[cur_room] = true;
            visited_num++;
            for (auto r : rooms[cur_room]) {
                dfs(r, rooms);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.resize(rooms.size(), false);
        dfs(0, rooms);
        if (visited_num != rooms.size())
            return false;
        else
            return true;
    }
};
