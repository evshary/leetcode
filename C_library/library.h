#ifndef _LIBRARY_C_
#define _LIBRARY_C_

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void printTreeNodes(struct TreeNode* tree);
void freeTreeNodes(struct TreeNode* tree);

#endif /*_LIBRARY_C_*/