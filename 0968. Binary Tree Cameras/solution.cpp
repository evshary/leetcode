/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int traverse(TreeNode* root, int & camera_num) {
        // 0: no cover
        // 1: camera
        // 2: cover
        if (root == nullptr) return 2; // make empty node means cover
        int left = traverse(root->left, camera_num);
        int right = traverse(root->right, camera_num);
        if (left == 0 || right == 0) {  // if one child is no cover, setup camera
            camera_num++;
            return 1;
        }
        if (left == 2 && right == 2) return 0; // both children are cover
        if (left == 1 || right == 1) return 2; // at least one child is camera
        return -1; // should never be here
    }
public:
    int minCameraCover(TreeNode* root) {
        int camera_num = 0;
        if (traverse(root, camera_num) == 0) {
            camera_num++;
        }
        return camera_num;
    }
};