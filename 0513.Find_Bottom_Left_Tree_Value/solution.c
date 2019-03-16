#include <stdio.h>
#include "../C_library/library.h"

static int bottom_depth;
static int bottom_left_val;

void findBottomLeftValue_r(struct TreeNode* root, int depth) {
    if (root == NULL)
        return;
    if (depth > bottom_depth) {
        bottom_depth = depth;
        bottom_left_val = root->val;
    }
    findBottomLeftValue_r(root->left, depth+1);
    findBottomLeftValue_r(root->right, depth+1);
}

int findBottomLeftValue(struct TreeNode* root) {
    bottom_depth = 0;
    bottom_left_val = 0;
    findBottomLeftValue_r(root, 1);
    return bottom_left_val;
}

int main() {
    //int nums[] = {2,1,3};
    int nums[] = {1,2,3,4,-1,5,6,-1,-1,7};
    //int nums[] = {1};
    struct TreeNode *root = genTreeFromArray(nums, sizeof(nums)/sizeof(nums[0]), -1);
    printf("left value: %d\n", findBottomLeftValue(root));
    return 0;
}