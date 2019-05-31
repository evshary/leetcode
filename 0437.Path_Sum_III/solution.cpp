#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#if 1 // another simple way
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return calSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int calSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return (sum == root->val) + calSum(root->left, sum-root->val) + calSum(root->right, sum-root->val);
    }
};
#elif 1
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        sum_num = 0;
        vector<int> comp_arr{sum};
        pathSum_r(root, comp_arr, sum);
        return sum_num;
    }
private:
    int sum_num;
    void pathSum_r(TreeNode* root, vector<int>& comp_arr, int sum) {
        if (root == NULL) return;
        for (int i = 0; i < comp_arr.size(); i++) {
            if (comp_arr[i] == root->val)
                sum_num++;
            comp_arr[i] -= root->val;
        }
        comp_arr.push_back(sum);
        pathSum_r(root->left, comp_arr, sum);
        pathSum_r(root->right, comp_arr, sum);
        comp_arr.pop_back();
        for (int i = 0; i < comp_arr.size(); i++) {
            comp_arr[i] += root->val;
        }
    }
};
#endif