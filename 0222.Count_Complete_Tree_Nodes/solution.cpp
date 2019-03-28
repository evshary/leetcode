class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh == rh)
            return (1 << lh) + countNodes(root->right);
        else
            return (1 << rh) + countNodes(root->left);
    }
private:
    int height(TreeNode *root) {
        int tree_height = 0;
        while (root != 0) {
            tree_height++;
            root = root->left;
        }
        return tree_height;
    }
};