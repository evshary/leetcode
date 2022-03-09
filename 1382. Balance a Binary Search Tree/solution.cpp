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
    vector<TreeNode *> treenode_array;
public:
    void inorder_traverse(TreeNode* root) {
        if (root == nullptr) return;
        inorder_traverse(root->left);
        treenode_array.push_back(root);
        inorder_traverse(root->right);
    }
    TreeNode *createBalanceTree(int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        treenode_array[mid]->left = createBalanceTree(start, mid-1);
        treenode_array[mid]->right = createBalanceTree(mid+1, end);
        return treenode_array[mid];
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder_traverse(root);
        return createBalanceTree(0, treenode_array.size()-1);
    }
};