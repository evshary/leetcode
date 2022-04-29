/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int,vector<TreeNode*>> hash;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> result;
        if (n % 2 == 0) return result;
        if (n == 1) return vector<TreeNode*>{new TreeNode(0)};
        for (int i = 1; i < n; i+=2) {
            vector<TreeNode*> left_list, right_list;
            if (hash.count(i)) {
                left_list = hash[i];
            } else {
                left_list = allPossibleFBT(i);
                hash[i] = left_list;
            }
            if (hash.count(n-1-i)) {
                right_list = hash[n-1-i];
            } else {
                right_list = allPossibleFBT(n-1-i);
                hash[n-1-i] = right_list;
            }
            for (auto l : left_list) {
                for (auto r : right_list) {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};