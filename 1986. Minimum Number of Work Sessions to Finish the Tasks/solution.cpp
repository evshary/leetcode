#if 1
class Solution {
private:
    int dfs(vector<int>& tasks, int remain_task, int max_session, int cur_session, int bitmask, unordered_map<int,int>& mem) {
        if (remain_task == 0) return 1;
        if (mem.count(cur_session << 16 | bitmask)) return mem[cur_session << 16 | bitmask];
        int result = INT_MAX;
        for (int i = 0; i < tasks.size(); i++) {
            if (!(bitmask & (1 << i))) {
                int group;
                if (tasks[i] + cur_session <= max_session) {
                    group = dfs(tasks, remain_task-1, max_session, tasks[i] + cur_session, bitmask | (1 << i), mem);
                } else {
                    group = 1 + dfs(tasks, remain_task-1, max_session, tasks[i], bitmask | (1 << i), mem);
                }
                result = min(result, group);
            }
        }
        mem[cur_session << 16 | bitmask] = result;
        return result;
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        unordered_map<int,int> mem;
        return dfs(tasks, tasks.size(), sessionTime, 0, 0, mem);
    }
};
#else // TLE
class Solution {
private:
    int dfs(vector<int>& tasks, int remain_task, int max_session, int cur_session, int bitmask) {
        if (remain_task == 0) return 1;
        int result = INT_MAX;
        for (int i = 0; i < tasks.size(); i++) {
            if (!(bitmask & (1 << i))) {
                int group;
                if (tasks[i] + cur_session <= max_session) {
                    group = dfs(tasks, remain_task-1, max_session, tasks[i] + cur_session, bitmask | (1 << i));
                } else {
                    group = 1 + dfs(tasks, remain_task-1, max_session, tasks[i], bitmask | (1 << i));
                }
                result = min(result, group);
            }
        }
        return result;
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        return dfs(tasks, tasks.size(), sessionTime, 0, 0);
    }
};
#endif