/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (head == NULL) return NULL;
    int node_num = 1;
    struct ListNode *last = NULL, *current = head, *next = head->next;
    struct ListNode *before_m, *m_node;
    // stop at m
    while (node_num < m) {
        last = current;
        current = next;
        if (next) next = next->next;
        node_num++;
    }
    before_m = last;
    m_node = current;
    // reverse
    while (node_num >= m && node_num <= n) {
        current->next = last; // reverse
        last = current;
        current = next;
        if (next) next = next->next;
        node_num++;
    }
    m_node->next = current;
    if (before_m != NULL) {
        before_m->next = last;
        return head;
    } else {
        return last;
    }
}