#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "../C_library/library.h"

int minDepth_r(struct TreeNode* root, int depth) {
    if (root == NULL)
        return INT_MAX;
    if (root->left == NULL && root->right == NULL) {
        return depth;
    }
    return fmin(minDepth_r(root->left, depth+1), minDepth_r(root->right, depth+1));
}

int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    return minDepth_r(root, 1);
}

int main() {
    //int array[] = {3,9,20,-1,-1,15,7};
    int array[] = {1,2};
    struct TreeNode *root = genTreeFromArray(array, ARRAY_SIZE(array), -1);
    printf("min depth: %d\n", minDepth(root));
    return 0;
}