#include <stdbool.h>

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

bool checkSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL || q == NULL) {
        if (p == q)
            return true;
        else
            return false;
    }
    if (!checkSameTree(p->left, q->left))
        return false;
    if (p->val != q->val)
        return false;
    if (!checkSameTree(p->right, q->right))
        return false;
    return true;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return checkSameTree(p, q);
}

int main() {
    printf("I don't write the test case for this problems.\n");
    return 0;
}