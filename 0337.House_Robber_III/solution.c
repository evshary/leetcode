#include "../C_library/library.h"
#include <stdio.h>
#include <math.h>

void rob_r(struct TreeNode *root, int *rob_sum, int *not_rob_sum) {
    if (root == NULL) {
        *rob_sum = 0;
        *not_rob_sum = 0;
        return;
    }
    int lrob_sum, lnot_rob_sum;
    int rrob_sum, rnot_rob_sum;
    rob_r(root->left, &lrob_sum, &lnot_rob_sum);
    rob_r(root->right, &rrob_sum, &rnot_rob_sum);
    int tmp_result = fmax(lrob_sum+rnot_rob_sum, rrob_sum+lnot_rob_sum);
    tmp_result = fmax(tmp_result, lnot_rob_sum+rnot_rob_sum);
    *not_rob_sum = fmax(tmp_result, lrob_sum+rrob_sum);
    *rob_sum = lnot_rob_sum+rnot_rob_sum+root->val;
}

int rob(struct TreeNode* root) {
    int rob_sum, not_rob_sum;
    rob_r(root, &rob_sum, &not_rob_sum);
    return fmax(rob_sum, not_rob_sum);
}

int main() {
    //int array[] = {3,2,3,-1,3,-1,1}; //7
    //int array[] = {3,4,5,1,3,-1,1}; //9
    int array[] = {3}; //3
    //int array[] = {4,1,-1,2,-1,3}; //7
    //int array[] = {1,2,50,51,1}; //102
    //int array[] = {41,37,44,24,39,42,48,1,35,38,40,-1,43,46,49,0,2,30,36,-1,-1,-1,-1,-1,-1,45,47,-1,-1,-1,-1,-1,4,29,32,-1,-1,-1,-1,-1,-1,3,9,26,-1,31,34,-1,-1,7,11,25,27,-1,-1,33,-1,6,8,10,16,-1,-1,-1,28,-1,-1,5,-1,-1,-1,-1,-1,15,19,-1,-1,-1,-1,12,-1,18,20,-1,13,17,-1,-1,22,-1,14,-1,-1,21,23}; //690
    struct TreeNode *root = genTreeFromArray(array, ARRAY_SIZE(array), -1);;
    printf("Total money: %d\n", rob(root));
    freeTreeNodes(root);
    return 0;
}