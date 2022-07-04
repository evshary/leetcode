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
	void traverse(vector<int> &result, TreeNode* root, int depth) {
		if (root == nullptr) return;
		if (result.size() <= depth) result.push_back(0);
		traverse(result, root->left, depth+1);
		result[depth] = root->val;
		traverse(result, root->right, depth+1);
	}
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        traverse(result, root, 0);
        return result;
    }
};