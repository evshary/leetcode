#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../C_library/library.h"

#if 0
static int last_depth, last_depth2;

bool isBalanced_r(struct TreeNode* root, int depth) {
    if (root == NULL)
        return true;
    if (root->left == NULL || root->right == NULL) {
        if (last_depth == 0) {
            last_depth = depth;
        } else if (last_depth2 == 0) {
            last_depth2 = depth;
        } else if (depth != last_depth && depth != last_depth2) {
            return false;
        }
    }
    return isBalanced_r(root->left, depth+1) && isBalanced_r(root->right, depth+1);
}

bool isBalanced(struct TreeNode* root) {
    last_depth = last_depth2 = 0;
    if (isBalanced_r(root, 1) && abs(last_depth - last_depth2) <= 1)
        return true;
    else
        return false;
}
#else
#define UNBALANCED -1

int depth(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    int left_depth = depth(root->left);
    if (left_depth == UNBALANCED)
        return UNBALANCED;
    int right_depth = depth(root->right);
    if (right_depth == UNBALANCED)
        return UNBALANCED;
    if (abs(left_depth-right_depth) > 1)
        return UNBALANCED;
    return fmax(right_depth, left_depth)+1;
}

bool isBalanced(struct TreeNode* root) {
    return depth(root) != UNBALANCED;
}
#endif

int main() {
    int array[] = {3,9,20,-1,-1,15,7};  // true
    //int array[] = {1,2,2,3,3,-1,-1,4,4};  // false
    //int array[] = {1,-1,2,-1,3};  // false
    //int array[] = {1,-1,2,-1,3,-1,4};  // false
    //int array[] = {1};  // true
    //int array[] = {1,2,3}; // true
    //int array[] = {1,2}; // true
    //int array[] = {1,2,2,3,-1,-1,3,4,-1,-1,4}; // false
    //int array[] = {1,2,2,3,3,3,3,4,4,4,4,4,4,-1,-1,5,5}; // true
    struct TreeNode *root = genTreeFromArray(array, ARRAY_SIZE(array), -1);
    if (isBalanced(root))
        printf("true\n");
    else
        printf("false\n");
    freeTreeNodes(root);
    return 0;
}