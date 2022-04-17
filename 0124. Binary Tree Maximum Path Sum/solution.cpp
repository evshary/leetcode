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
    int max_num;
    int maxPathSum_r(TreeNode* node) {
        if (node == nullptr) return 0;
        // if left / right < 0, then don't choose it
        int left_max = max(maxPathSum_r(node->left), 0);
        int right_max = max(maxPathSum_r(node->right), 0);
        // Update the max_num
        max_num = max(max_num, node->val + left_max + right_max);
        // Only return one side of the node and the node value
        return node->val + max(left_max, right_max);
    }
public:
    int maxPathSum(TreeNode* root) {
        max_num = root->val;
        maxPathSum_r(root);
        return max_num;
    }
};