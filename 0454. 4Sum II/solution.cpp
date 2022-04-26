#if 1
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> hash;
        int result = 0;
        for (auto n1 : nums1) {
            for (auto n2: nums2) {
                hash[n1+n2]++;
            }
        }
        for (auto n3 : nums3) {
            for (auto n4 : nums4) {
                if (hash.count(-(n3+n4))) result += hash[-(n3+n4)];
            }
        }
        return result;
    }
};
#else
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int result = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        sort(nums4.begin(), nums4.end());
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int left = 0, right = nums4.size() - 1;
                int sum12 = nums1[i] + nums2[j];
                while (left < nums3.size() && right >= 0) {
                    int sum34 = nums3[left] + nums4[right];
                    if (sum12 + sum34 == 0) {
                        left++; right--;
                        int same_left_num = 1;
                        int same_right_num = 1;
                        while (left < nums3.size() && nums3[left] == nums3[left-1]) {
                            same_left_num++;
                            left++;
                        }
                        while (right >= 0 && nums4[right] == nums4[right+1]) {
                            same_right_num++;
                            right--;
                        }
                        result += same_left_num * same_right_num;
                    } else if (sum12 + sum34 > 0) {
                        right--;
                    } else if (sum12 + sum34 < 0) {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
#endif