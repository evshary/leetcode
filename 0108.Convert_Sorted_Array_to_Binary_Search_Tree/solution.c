#include <stdio.h>
#include <stdlib.h>
#include "../C_library/library.h"

struct TreeNode* sortedArrayToBST_r(int* nums, int first, int last) {
    if (first == last) {
        //printf("first=last=%d NULL\n",first);
        return NULL;
    }
    int middle = (first + last) / 2;
    //printf("first=%d last=%d middle=%d\n", first, last, middle);
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = nums[middle];
    if (first != middle) {
        node->left = sortedArrayToBST_r(nums, first, middle);
        node->right = sortedArrayToBST_r(nums, middle+1, last);
    } else {
        node->left = node->right = NULL;
    }
    return node;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return sortedArrayToBST_r(nums, 0, numsSize);
}

int main() {
    int nums[] = {-10,-3,0,5,9};
    struct TreeNode* node = sortedArrayToBST(nums, sizeof(nums)/sizeof(nums[0]));
    printTreeNodes(node);
    freeTreeNodes(node);
    return 0;
}