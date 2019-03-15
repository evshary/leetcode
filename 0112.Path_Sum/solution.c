#include <stdbool.h>
#include "../C_library/library.h"
#include <stdio.h>

bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL)
        return false;
    if (root->left && hasPathSum(root->left, sum - root->val))
        return true;
    if (root->right && hasPathSum(root->right, sum - root->val))
        return true;
    if (root->left == NULL && root->right == NULL && root->val == sum)
        return true;
    return false;
}

int main() {
    int array[] = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,1};
    int sum = 22;
    //int array[] = {1,2};
    //int sum = 1;
    struct TreeNode *root = genTreeFromArray(array, sizeof(array)/sizeof(array[0]), -1);
    if (hasPathSum(root, sum))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}