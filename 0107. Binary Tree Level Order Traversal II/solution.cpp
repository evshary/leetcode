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
    vector<vector<int>> result;
    void traverse(TreeNode* node, int depth) {
        if (node == nullptr) return;
        if (depth+1 > result.size())
            result.push_back({});
        result[depth].push_back(node->val);
        traverse(node->left, depth+1);
        traverse(node->right, depth+1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        traverse(root, 0);
        reverse(result.begin(), result.end());
        return result;
    }
};