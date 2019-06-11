#include <math.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max_len;

int diameterOfBinaryTree_r(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left_edge = diameterOfBinaryTree_r(root->left);
    int right_edge = diameterOfBinaryTree_r(root->right);
    max_len = fmax(max_len, left_edge+right_edge);
    return fmax(left_edge, right_edge) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    max_len = 0;
    diameterOfBinaryTree_r(root);
    return max_len;
}