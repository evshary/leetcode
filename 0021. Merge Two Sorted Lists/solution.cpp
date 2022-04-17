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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
#if 1  // recursion
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
#else
        ListNode *merge_head = nullptr, *merge_end = nullptr, *nextptr;
        while (list1 || list2) {
            if (list1 == nullptr) {
                nextptr = list2;
                list2 = list2->next;
            } else if (list2 == nullptr) {
                nextptr = list1;
                list1 = list1->next;
            } else {
                if (list1->val <= list2->val) {
                    nextptr = list1;
                    list1 = list1->next;
                } else {
                    nextptr = list2;
                    list2 = list2->next;
                }
            }
            if (merge_end == nullptr) {
                merge_head = merge_end = nextptr;
            } else {
                merge_end->next = nextptr;
                merge_end = merge_end->next;
            }
        }
        return merge_head;
#endif
    }
};