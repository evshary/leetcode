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
private:
    ListNode* mergeLists(ListNode *list1, ListNode *list2) {
        ListNode dummy;
        ListNode *ptr = &dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if (list1) {
            ptr->next = list1;
        }
        if (list2) {
            ptr->next = list2;
        }
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode *head = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            head = mergeLists(head, lists[i]);
        }
        return head;
    }
};