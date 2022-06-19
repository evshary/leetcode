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
    bool compare(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left != nullptr && right != nullptr) {
            if (left->val != right->val) return false;
            if (compare(left->left, right->right) && compare(left->right, right->left)) {
                return true;
            }
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return compare(root->left, root->right);
    }
};