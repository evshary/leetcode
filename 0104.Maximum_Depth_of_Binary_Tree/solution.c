#include <stdio.h>
#include <math.h>
#include "../C_library/library.h"

int maxDepth_r(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int depth = fmax(maxDepth_r(root->left), maxDepth_r(root->right));
    return depth+1;
}

int maxDepth(struct TreeNode* root) {
    return maxDepth_r(root);
}

int main() {
    int array[] = {3,9,20,-1,-1,15,7};
    struct TreeNode *root = genTreeFromArray(array, sizeof(array)/sizeof(array[0]), -1);
    printf("maxDepth: %d\n", maxDepth(root));
    freeTreeNodes(root);
    return 0;
}