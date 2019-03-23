#include "../C_library/library.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int **ret_array;
int ret_array_size;
int max_ret_array_size;
int *column_size;
/* stack */
int *stack;
int stack_ptr;
int max_stack_size;

void pathSum_r(struct TreeNode* root, int sum) {
    if (root == NULL)
        return;
    if (stack_ptr == max_stack_size) {
        max_stack_size *= 2;
        stack = realloc(stack, sizeof(int) * max_stack_size);
    }
    stack[stack_ptr++] = root->val;
    if (root->left == NULL && root->right == NULL) {
        if (sum != root->val) {
            stack_ptr--;
            return;
        }
        if (ret_array_size == max_ret_array_size) {
            max_ret_array_size *= 2;
            ret_array = realloc(ret_array, sizeof(int *) * max_ret_array_size);
            column_size = realloc(column_size, sizeof(int) * max_ret_array_size);
        }
        ret_array[ret_array_size] = malloc(sizeof(int) * stack_ptr);
        memcpy(ret_array[ret_array_size], stack, sizeof(int) * stack_ptr);
        column_size[ret_array_size] = stack_ptr;
        ret_array_size++;
    } else {
        if (root->left != NULL) {
            pathSum_r(root->left, sum - root->val);
        }
        if (root->right != NULL) {
            pathSum_r(root->right, sum - root->val);
        }
    }
    stack_ptr--;
}

int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
    ret_array_size = 0;
    max_ret_array_size = 5;
    ret_array = malloc(sizeof(int *) * max_ret_array_size);
    column_size = malloc(sizeof(int) * max_ret_array_size);
    stack_ptr = 0;
    max_stack_size = 10;
    stack = malloc(sizeof(int) * max_stack_size);
    pathSum_r(root, sum);
    *columnSizes = column_size;
    *returnSize = ret_array_size;
    return ret_array;
}

int main() {
    int array[] = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
    int sum = 22;
    int *columnSizes;
    int returnSize;
    struct TreeNode *root = genTreeFromArray(array, ARRAY_SIZE(array), -1);
    int **ret_array = pathSum(root, sum, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", ret_array[i][j]);
        }
        printf("\n");
        free(ret_array[i]);
    }
    free(ret_array);
    free(columnSizes);
}