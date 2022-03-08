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
    void dfs_tree(TreeNode *root, vector<int> & tree_seq) {
        if (root == nullptr)
            return;
        dfs_tree(root->left, tree_seq);
        tree_seq.push_back(root->val);
        dfs_tree(root->right, tree_seq);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1_seq, tree2_seq;
        vector<int> res;
        dfs_tree(root1, tree1_seq);
        dfs_tree(root2, tree2_seq);
        for (int i = 0, j = 0; i < tree1_seq.size() || j < tree2_seq.size(); ) {
            if (i == tree1_seq.size()) {
                res.push_back(tree2_seq[j]);
                j++;
            } else if (j == tree2_seq.size()) {
                res.push_back(tree1_seq[i]);
                i++;
            } else if (tree1_seq[i] <= tree2_seq[j]) {
                res.push_back(tree1_seq[i]);
                i++;
            } else {
                res.push_back(tree2_seq[j]);
                j++;
            }
        }
        return res;
    }
};