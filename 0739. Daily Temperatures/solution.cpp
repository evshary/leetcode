#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

#if 1 // Using stack is better idea
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        stack<pair<int,int>> s;
        for (int i = 0; i < T.size(); i++) {
            while (!s.empty() && s.top().second < T[i]) {
                result[s.top().first] = i - s.top().first;
                s.pop();
            }
            s.push(make_pair(i, T[i]));
        }
        return result;
    }
};
#elif 1 // TLE while there are too many duplicate number, like 71,76,71,76.....
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        list<pair<int,int>> l;
        int min_num = INT_MAX;
        for (int i = 0; i < T.size(); i++) {
            if (min_num < T[i]) {
                for (auto it = l.begin(); it != l.end();) {
                    auto pit = it++;
                    if (pit->second < T[i]) {
                        result[pit->first] = i - pit->first;
                        l.erase(pit);
                    }
                }
            }
            min_num = min(min_num, T[i]);
            l.push_back(make_pair(i, T[i]));
        }
        return result;
    }
};
#endif

int main() {
    vector<int> temperature{73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    vector<int> result = s.dailyTemperatures(temperature);
    for (auto t : result)
        cout << t << " ";
    cout << endl;
    return 0;
}