/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int node_num = 0;
        // Calculate the number of node
        for (ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
            node_num++;
        }
        // Get the k-th node from start and end
        ListNode *k_node, *r_k_node;
        int node_cnt = 0;
        for (ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
            node_cnt++;
            if (node_cnt == k) {
                k_node = ptr;
            }
            if (node_cnt == node_num - k + 1) {
                r_k_node = ptr;
            }
        }
        // Swap two nodes
        swap(k_node->val, r_k_node->val);
        return head;
    }
};