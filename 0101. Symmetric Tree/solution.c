#include "../C_library/library.h"
#include <stdio.h>
#include <stdbool.h>

bool isSymmetric_r(struct TreeNode* lnode, struct TreeNode* rnode) {
    if (lnode == NULL || rnode == NULL) {
        if (lnode == NULL && rnode == NULL)
            return true;
        else
            return false;
    }
    return lnode->val == rnode->val && isSymmetric_r(lnode->left, rnode->right) && isSymmetric_r(lnode->right, rnode->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return isSymmetric_r(root->left, root->right);
}

int main() {
    //int array[] = {1,2,2,3,4,4,3}; // true
    //int array[] = {1,2,2,-1,3,-1,3}; // false
    //nt array[] = {1}; // true
    int array[] = {1,-1,2}; // false
    struct TreeNode *root = genTreeFromArray(array, ARRAY_SIZE(array), -1);
    if (isSymmetric(root))
        printf("true\n");
    else
        printf("false\n");
    freeTreeNodes(root);
    return 0;
}