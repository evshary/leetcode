/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int *in_array;
int *post_array;

struct TreeNode* buildTree_r(int in_start, int in_stop, int post_start, int post_stop) {
    if (in_stop < in_start || post_stop < post_start) return NULL;
    int medium = post_array[post_stop];
    int in_med_offset = 0;
    while (in_array[in_start + in_med_offset] != medium) {
        in_med_offset++;
    }
    struct TreeNode *ptr = malloc(sizeof(struct TreeNode));
    ptr->val = medium;
    ptr->left = buildTree_r(in_start, in_start+in_med_offset-1, post_start, post_start+in_med_offset-1);
    ptr->right = buildTree_r(in_start+in_med_offset+1, in_stop, post_start+in_med_offset, post_stop-1);
    return ptr;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    in_array = inorder;
    post_array = postorder;
    return buildTree_r(0, inorderSize-1, 0, postorderSize-1);
}
