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
    int result = 0;
    void traverse(TreeNode* node, int number) {
        if (node->left == nullptr && node->right == nullptr) {
            result += number * 2 + node->val;
        }
        if (node->left != nullptr) {
            traverse(node->left, number * 2 + node->val);
        }
        if (node->right != nullptr) {
            traverse(node->right, number * 2 + node->val);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        traverse(root, 0);
        return result;
    }
};