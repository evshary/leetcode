/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#if 1
class Solution {
public:
    Node* connect(Node* root) {
        Node *prev_ptr = root;
        Node *cur_head = nullptr, *cur_ptr;
        while (prev_ptr != nullptr) {
            while (prev_ptr != nullptr) {
                if (prev_ptr->left) {
                    if (cur_head == nullptr) {
                        cur_head = prev_ptr->left;
                    } else {
                        cur_ptr->next = prev_ptr->left;
                    }
                    cur_ptr = prev_ptr->left;
                }
                if (prev_ptr->right) {
                    if (cur_head == nullptr) {
                        cur_head = prev_ptr->right;
                    } else {
                        cur_ptr->next = prev_ptr->right;
                    }
                    cur_ptr = prev_ptr->right;
                }
                prev_ptr = prev_ptr->next;
            }
            prev_ptr = cur_head;
            cur_head = nullptr;
        }
        return root;
    }
};
#else  // space O(logN)
class Solution {
private:
    void traverse(Node* node, int layer, vector<Node *>& last_node) {
        if (node == nullptr) return;
        if (last_node.size() < layer) {
            last_node.push_back(node);
        } else {
            last_node[layer-1]->next = node;
            last_node[layer-1] = node;
        }
        traverse(node->left, layer+1, last_node);
        traverse(node->right, layer+1, last_node);
    }
public:
    Node* connect(Node* root) {
        vector<Node *> last_node;
        traverse(root, 1, last_node);
        return root;
    }
};
#endif