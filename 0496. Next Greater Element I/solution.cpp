#if 1
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> hash;
        stack<int> s;
        for (auto n : nums2) {
            while (!s.empty() && s.top() < n) {
                hash[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        for (auto n : nums1) {
            ans.push_back(hash.count(n)?hash[n]:-1);
        }
        return ans;
    }
};
#else  // O(NM) while N = nums1.size() and M = nums2.size()
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> hash;
        for (int i = 0; i < nums2.size(); i++) {
            hash[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = hash[nums1[i]]; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    ans.push_back(nums2[j]);
                    break;
                }
            }
            if (ans.size() != i+1) ans.push_back(-1);
        }
        return ans;
    }
};
#endif