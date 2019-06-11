/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void convertBST_r(struct TreeNode* root, int *sum) {
    if (root->right)
        convertBST_r(root->right, sum);
    root->val += *sum;
    *sum = root->val;
    if (root->left)
        convertBST_r(root->left, sum);
}

struct TreeNode* convertBST(struct TreeNode* root){
    int sum = 0;
    if (root)
        convertBST_r(root, &sum);
    return root;
}
