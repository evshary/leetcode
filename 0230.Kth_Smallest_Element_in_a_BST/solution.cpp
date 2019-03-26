#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
public:
    int kthSmallest_r(TreeNode *root, int k) {
        int value;
        if (root->left && (value=kthSmallest_r(root->left, k)) != INT_MIN)
            return value;
        path++;
        if (k == path)
            return root->val;
        if (root->right && (value=kthSmallest_r(root->right, k)) != INT_MIN)
            return value;
        return INT_MIN;
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == 0)
            return 0;
        path = 0;
        return kthSmallest_r(root, k);
    }
private:
    int path;
};