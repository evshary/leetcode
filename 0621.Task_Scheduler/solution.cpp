#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#if 1 // without hash table
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int task_table[26] = {0};
        int max_times = 0, max_times_cnt = 0;
        for (auto t : tasks) {
            task_table[t-'A']++;
            if (task_table[t-'A'] > max_times) {
                max_times = task_table[t-'A'];
                max_times_cnt = 1;
            } else if (task_table[t-'A'] == max_times) {
                max_times_cnt++;
            }
        }
        // count the all the interval
        int interval = (max_times-1)*(n-(max_times_cnt-1));
        // count the remain tasks
        int remain_tasks = tasks.size()-(max_times*max_times_cnt);
        // count the idle tasks
        int idle = max(interval - remain_tasks, 0);
        return tasks.size() + idle;
    }
};
#else
bool comp_func(int l, int r) {
    return r < l;
}

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty()) return 0;
        if (n == 0) return tasks.size();
        unordered_map<char,int> htable;
        for (auto t : tasks) {
            htable[t] += 1;
        }
        vector<int> v;
        for (auto h : htable) {
            v.push_back(h.second);
        }
        sort(v.begin(), v.end(), comp_func);
        int appear_times = v[0], repeat_appear_times = count(v.begin(), v.end(), v[0]);
        int interval = (appear_times-1)*(n-(repeat_appear_times-1));
        int remain_tasks = tasks.size() - appear_times*repeat_appear_times;
        int idle = max(interval - remain_tasks, 0);
        return tasks.size()+idle;
    }
};
#endif

int main() {
    vector<char> tasks{'A','A','A','B','B','B'};
    int n = 2;
    Solution s;
    cout << s.leastInterval(tasks, n) << endl;;
    return 0;
}