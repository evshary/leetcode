#include <stdio.h>
#include "../C_library/library.h"

struct TreeNode* flatten_r(struct TreeNode* current) {
    if (current == NULL)
        return NULL;
    struct TreeNode* left = current->left;
    struct TreeNode* right = current->right;
    struct TreeNode* retNode = current;
    //printf("cur->val=%d\n", current->val);
    if (left != NULL) {
        //printf("left->val=%d\n", left->val);
        current->left = NULL;
        current->right = left;
        retNode = flatten_r(left);
    }
    if (right != NULL) {
        //printf("right->val=%d\n", right->val);
        retNode->right = right;
        retNode = flatten_r(right);
    }
    return retNode;
}

void flatten(struct TreeNode* root) {
    flatten_r(root);
    return;
}

int main () {
    int array[] = {1,2,5,3,4,-1,6};
    struct TreeNode *root = genTreeFromArray(array, sizeof(array)/sizeof(array[0]), -1);
    flatten(root);
    printTreeNodes(root);
    freeTreeNodes(root);
    return 0;
}