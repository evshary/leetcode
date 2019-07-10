#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> p_stack, q_stack;
        lowestCommonAncestor_r(root, p, p_stack);
        lowestCommonAncestor_r(root, q, q_stack);
        int stack_size = min(p_stack.size(), q_stack.size());
        TreeNode *result = NULL;
        for (int i = 0; i < stack_size; i++) {
            if (p_stack[i] == q_stack[i])
                result = p_stack[i];
            else
                break;
        }
        return result;
    }
private:
    bool lowestCommonAncestor_r(TreeNode* root, TreeNode* t, vector<TreeNode *> &s) {
        if (root == NULL || t == NULL) return false;
        s.push_back(root);
        if (root->val == t->val) return true;
        if (lowestCommonAncestor_r(root->left, t, s) || lowestCommonAncestor_r(root->right, t, s))
            return true;
        s.pop_back();
        return false;
    }
};