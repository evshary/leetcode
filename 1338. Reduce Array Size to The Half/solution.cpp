class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> occur;
        for (auto i : arr) {
            if (occur.find(i) == occur.end()) {
                occur[i] = 1;
            } else {
                occur[i]++;
            }
        }
        priority_queue<pair<int,int>> occur_queue;
        for (auto o : occur) {
            occur_queue.push({o.second, o.first});
        }
        int res = 0;
        int total_cnt = 0;
        while (!occur_queue.empty()) {
            auto p = occur_queue.top();
            occur_queue.pop();
            res++;
            total_cnt += p.first;
            if (total_cnt >= (arr.size()/2))
                break;
        }
        return res;
    }
};
