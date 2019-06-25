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
    vector<string> binaryTreePaths(TreeNode* root) {
        result.clear();
        vector<int> value;
        TreeTraversal(root, value);
        return result;
    }
private:
    void TreeTraversal(TreeNode* root, vector<int>& value) {
        if (root == NULL)  return;
        value.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            string str = to_string(value[0]);
            for (int i = 1; i < value.size(); i++) {
                str += "->" + to_string(value[i]);
            }
            result.push_back(str);
        } else {
            TreeTraversal(root->left, value);
            TreeTraversal(root->right, value);
        }
        value.pop_back();
    }
    vector<string> result;
};