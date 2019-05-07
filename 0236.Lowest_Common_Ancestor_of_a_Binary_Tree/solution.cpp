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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA = NULL;
        lowestCommonAncestor_r(root, p, q);
        return LCA;
    }
private:
    TreeNode* LCA;
    bool lowestCommonAncestor_r(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool left = false, current = false, right = false;
        if (LCA != NULL) return true;
        if (root == NULL)
            return false;
        else if (root == p || root == q)
            current = true;
        left = lowestCommonAncestor_r(root->left, p, q);
        right = lowestCommonAncestor_r(root->right, p, q);
        if ((left && right) || (left && current) || (right && current)) {
            if (LCA == NULL) LCA = root;
            return true;
        } else if (left || right || current) {
            return true;
        } else {
            return false;
        }
    }
};