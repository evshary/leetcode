#include <stdio.h>
#include <stdlib.h>
#include "../C_library/library.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NODE_NUM 100
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ret_array = malloc(MAX_NODE_NUM * sizeof(int));
    *returnSize = 0;
    struct TreeNode* stacks[MAX_NODE_NUM];
    int stack_next_ptr = 0;
    while(root != NULL || stack_next_ptr != 0) {
        while (root != NULL) {
            stacks[stack_next_ptr++] = root;
            root = root->left;
        }
        root = stacks[--stack_next_ptr];
        ret_array[(*returnSize)++] = root->val;
        root = root->right;
    }
    return ret_array;
}

int main() {
    int nums[] = {1,-1,2,3};
    int returnSize;
    struct TreeNode* root = genTreeFromArray(nums, sizeof(nums)/sizeof(nums[0]), -1);
    //printTreeNodes(root);
    int *ret_array = inorderTraversal(root, &returnSize);
    for(int i = 0; i < returnSize; i++)
        printf("%d ", ret_array[i]);
    printf("\n");
    freeTreeNodes(root);
    return 0;
}