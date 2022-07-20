#define BUCKET_SIZE 10000

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int min_num = INT_MAX, max_num = INT_MIN;
        for (auto n : nums) {
        	min_num = min(min_num, n);
        	max_num = max(max_num, n);
        }
        int bucket_num = (max_num - min_num + 1)/BUCKET_SIZE + 1;
        vector<vector<int>> buckets(bucket_num);
        for (auto n : nums) {
        	buckets[(n - min_num)/BUCKET_SIZE].push_back(n);
        }
        int last_num = min_num;
        int max_diff = 0;
        for (int i = 0; i < bucket_num; i++) {
        	sort(buckets[i].begin(), buckets[i].end());
        	for (int j = 0; j < buckets[i].size(); j++) {
        		max_diff = max(max_diff, buckets[i][j] - last_num);
        		last_num = buckets[i][j];
        	}
        }
        return max_diff;
    }
};