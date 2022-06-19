class Solution {
public:
    int sumOfLeftLeaves_r(TreeNode* root, bool left) {
        int num = 0;
        if (root == 0)
            return 0;
        if (left && root->left == 0 && root->right == 0)
            return root->val;
        if (root->left)
            num += sumOfLeftLeaves_r(root->left, true);
        if (root->right)
            num += sumOfLeftLeaves_r(root->right, false);
        return num;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves_r(root, false);
    }
};