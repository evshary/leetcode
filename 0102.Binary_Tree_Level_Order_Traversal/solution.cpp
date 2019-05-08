#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        result.clear();
        levelOrder_r(root, 0);
        return result;
    }
private:
    vector<vector<int>> result;
    void levelOrder_r(TreeNode* root, int level) {
        if (root == NULL) return;
        while (result.size() < level+1)
            result.push_back({});
        result[level].push_back(root->val);
        levelOrder_r(root->left, level+1);
        levelOrder_r(root->right, level+1);
    }
};