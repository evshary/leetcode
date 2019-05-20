#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorder == NULL || inorder == NULL || preorderSize == 0 || preorderSize != inorderSize)
        return NULL;
    // get and build the middle
    struct TreeNode *middle = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (middle == NULL) return NULL;
    middle->val = preorder[0];
    middle->left = middle->right = NULL;
    if (preorderSize == 1) return middle;
    // Get the middle index
    int middle_idx = 0;
    while (inorder[middle_idx] != preorder[0]) middle_idx++;
    // middle->left = recursive the left
    middle->left = buildTree(preorder+1, middle_idx, inorder, middle_idx);
    // middle->right = recursive the right
    middle->right = buildTree(preorder+middle_idx+1, preorderSize-middle_idx-1, inorder+middle_idx+1, inorderSize-middle_idx-1);
    // return middle pointer
    return middle;
}