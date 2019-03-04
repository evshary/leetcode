#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

struct TreeNode* findTheMaxTree(int *nums, int left, int right) {
    if (left > right) {
        return NULL;
    }
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    int max_idx = left;
    for (int i = left; i <= right; i++) {
        if (nums[max_idx] < nums[i]) max_idx = i;
    }
    node->val = nums[max_idx];
    node->left = findTheMaxTree(nums, left, max_idx-1);
    node->right = findTheMaxTree(nums, max_idx+1, right);
    return node;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    return findTheMaxTree(nums, 0, numsSize-1);
}

int main() {
    int nums[] = {3,2,1,6,0,5};
    constructMaximumBinaryTree(nums, sizeof(nums)/sizeof(nums[0]));
    return 0;
}