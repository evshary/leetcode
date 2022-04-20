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
        if (root == nullptr) return nullptr;
        Node *n1 = root->left, *n2 = root->right;
        // connect the left and right node which are splitted by root
        while(n1 && n2) {
            n1->next = n2;
            n1 = n1->right;
            n2 = n2->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};
#else
class Solution {
private:
    vector<Node*> prev_node;
    void traverse(Node* node, int depth) {
        if (node == nullptr) return;
        if (depth+1 > prev_node.size()) {
            prev_node.push_back(node);
        } else {
            prev_node[depth]->next = node;
            prev_node[depth] = node;
        }
        traverse(node->left, depth+1);
        traverse(node->right, depth+1);
    }
public:
    Node* connect(Node* root) {
        traverse(root, 0);
        return root;
    }
};
#endif