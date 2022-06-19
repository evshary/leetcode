class Solution {
private:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[1] > v2[1];
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for (auto n : nums) {
            hash[n]++;
        }
        vector<vector<int>> v;
        for (auto h : hash) {
            v.push_back({h.first, h.second});
        }
        sort(v.begin(), v.end(), compare);
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(v[i][0]);
        }
        return result;
    }
};