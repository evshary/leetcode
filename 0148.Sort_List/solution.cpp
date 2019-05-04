struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *before_list, *cur_list, *after_list;
        ListNode *first, *second, *ptr, *sort;
        int list_size = 0;
        if (head == NULL) return NULL;
        for (ptr = head; ptr != NULL; ptr = ptr->next) list_size++;
        for (int i = 1; ; i *= 2) {
            cur_list = head;
            before_list = NULL;
            while(cur_list != NULL) {
                /* Get the pointer of two linked list which ends with NULL */
                second = first = cur_list;
                for (int j = i; j > 0 && second != NULL; j--) {
                    ptr = second;
                    second = ptr->next;
                }
                ptr->next = NULL;
                after_list = second;
                for (int j = i; j > 0 && after_list != NULL; j--) {
                    ptr = after_list;
                    after_list = ptr->next;
                }
                ptr->next = NULL;
                /* Sort first and second linked list */
                sort = sortTwoListNode(first, second);
                /* Link the sorted linked list back */
                if (before_list != NULL)
                    before_list->next = sort;
                else
                    head = sort;
                while(sort->next != NULL) sort = sort->next;
                sort->next = after_list;
                before_list = sort;
                cur_list = after_list;
            }
            if (i >= list_size) break;
        }
        return head;
    }
private:
    ListNode *sortTwoListNode(ListNode *l1, ListNode *l2) {
        ListNode *start, *ptr;
        /* Setup start pointer */
        if (l1 && l2 == NULL) return l1;
        else if (l1 == NULL && l2) return l2;
        if (l1->val <= l2->val) {
            start = l1;
            l1 = l1->next;
        } else {
            start = l2;
            l2 = l2->next;
        }
        /* Build sorted linked list */
        ptr = start;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL && l2) {
                ptr->next = l2;
                break;
            } else if (l1 && l2 == NULL) {
                ptr->next = l1;
                break;
            } else {
                if (l1->val <= l2->val) {
                    ptr->next = l1;
                    ptr = ptr->next;
                    l1 = l1->next;
                } else {
                    ptr->next = l2;
                    ptr = ptr->next;
                    l2 = l2->next;
                }
            }
        }
        return start;
    }
};