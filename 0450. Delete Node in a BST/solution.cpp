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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            TreeNode *new_node;
            if (root->left == nullptr && root->right == nullptr) {
                new_node = nullptr;
            } else if (root->left == nullptr) {
                new_node = root->right;
            } else if (root->right == nullptr) {
                new_node = root->left;
            } else {
                new_node = root->left;
                TreeNode *ptr = root->left;
                while (ptr->right) ptr = ptr->right;
                ptr->right = root->right;
            }
            delete(root);
            root = new_node;
        }
        return root;
    }
};