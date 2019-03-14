#include <stdbool.h>
#include <stdio.h>
#include "../C_library/library.h"

bool isValidBST_r(struct TreeNode* node, struct TreeNode* minNode, struct TreeNode* maxNode) {
    if (node == NULL)
        return true;
    if (node->left != NULL) {
        //printf("%d node->val=%d node->left->val=%d\n", __LINE__, node->val, node->left->val);
        if (node->val <= node->left->val)
            return false;
        if (minNode != NULL && minNode->val >= node->left->val)
            return false;
    }
    if (node->right != NULL) {
        //printf("%d node->val=%d node->right->val=%d\n", __LINE__, node->val, node->right->val);
        if (node->val >= node->right->val)
            return false;
        if (maxNode != NULL && maxNode->val <= node->right->val)
            return false;
    }
    if (!isValidBST_r(node->left, minNode, node) || !isValidBST_r(node->right, node, maxNode)) {
        return false;
    }
    return true;
}

bool isValidBST(struct TreeNode* root) {
    return isValidBST_r(root, NULL, NULL);
}

int main() {
    //int array[] = {2,1,3};
    //int NULL_int = -1;
    //int array[] = {5,1,4,-1,-1,3,6};
    //int NULL_int = -1;
    //int array[] = {10,5,15,-1,-1,6,20};
    //int NULL_int = -1;
    int array[] = {3,1,5,0,2,4,6};
    int NULL_int = -1;
    struct TreeNode* root = genTreeFromArray(array, sizeof(array)/sizeof(array[0]), NULL_int);
    if (isValidBST(root))
        printf("true\n");
    else
        printf("false\n");
    freeTreeNodes(root);
    return 0;
}