#include <queue>
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode *> tmp_queue;
        if (root)
            tmp_queue.push(root);
        while(tmp_queue.size()) {
            TreeNode *tmp = tmp_queue.front();
            swap(tmp->left, tmp->right);
            if (tmp->left)
                tmp_queue.push(tmp->left);
            if (tmp->right)
                tmp_queue.push(tmp->right);
            tmp_queue.pop();
        }
        return root;
    }
};