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
    int sum = 0;
    void traverse(TreeNode* node, int value) {
        int new_value = value * 10 + node->val;
        if (node->left != nullptr) {
            traverse(node->left, new_value);
        }
        if (node->right != nullptr) {
            traverse(node->right, new_value);
        }
        if (node->left == nullptr && node->right == nullptr){
            sum += new_value;
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        if (root)
            traverse(root, 0);
        return sum;
    }
};