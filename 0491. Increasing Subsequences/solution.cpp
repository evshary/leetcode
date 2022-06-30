class Solution {
private:
	void traverse(vector<vector<int>>& result, vector<int>& nums, int idx, vector<int>& subseq) {
		if (subseq.size() >= 2) {
			result.push_back(subseq);
		}
		unordered_set<int> sets;
		for (int i = idx; i < nums.size(); i++) {
			if (sets.count(nums[i])) continue;
			if (subseq.size() == 0 || subseq.back() <= nums[i]) {
				sets.insert(nums[i]);
				subseq.push_back(nums[i]);
				traverse(result, nums, i+1, subseq);
				subseq.pop_back();	
			}
		}
	}
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subseq;
        traverse(result, nums, 0, subseq);
        return result;
    }
};