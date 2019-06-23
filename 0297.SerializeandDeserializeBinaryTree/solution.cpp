#include <iostream>
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string buffer = "";
        saveIntoBuffer(root, buffer);
        return buffer;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode *> buffer;
        string token;
        size_t found, last_found = 0;
        while ((found = data.find(",", last_found)) != string::npos) {
            TreeNode *ptr;
            token = data.substr(last_found, found-last_found);
            last_found = found + 1;
            if (token != "null") {
                ptr = new TreeNode(stoi(token));
            } else {
                ptr = NULL;
            }
            buffer.push_back(ptr);
        }
        int idx = 0;
        TreeNode *result = bufferToTreeNode(buffer, idx);
        return result;
    }
private:
    void saveIntoBuffer(TreeNode* root, string& buffer) {
        if (root != NULL) {
            buffer += to_string(root->val) + ",";
            saveIntoBuffer(root->left, buffer);
            saveIntoBuffer(root->right, buffer);
        } else {
            buffer += "null,";
        }
    }
    TreeNode* bufferToTreeNode(vector<TreeNode *>& buffer, int& idx) {
        int cur_idx = idx;
        if (buffer[cur_idx] != NULL) {
            buffer[cur_idx]->left = bufferToTreeNode(buffer, ++idx);
            buffer[cur_idx]->right = bufferToTreeNode(buffer, ++idx);
        }
        return buffer[cur_idx];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main() {
    Codec codec;
    TreeNode node(10);
    string serial_str = codec.serialize(&node);
    cout << serial_str << endl;;
    cout << codec.deserialize(serial_str)->val << endl;
    return 0;
}