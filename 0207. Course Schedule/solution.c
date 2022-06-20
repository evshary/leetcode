#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode {
    struct LinkedListNode *next;
    int val;
};

struct LinkedListHead {
    struct LinkedListNode *start;
    struct LinkedListNode *end;
    int number;
};

struct LinkedListHead* initLinkedListHead() {
    struct LinkedListHead* head = malloc(sizeof(struct LinkedListHead));
    head->start = NULL;
    head->end = NULL;
    head->number = 0;
    return head;
}

void offerLinkedList(struct LinkedListHead *head, int val) {
    struct LinkedListNode *ptr = malloc(sizeof(struct LinkedListNode));
    ptr->next = NULL;
    ptr->val = val;
    if (head->start == NULL) {
        head->start = ptr;
    } else {
        head->end->next = ptr;
    }
    head->end = ptr;
    head->number++;
}

int pollLinkedList(struct LinkedListHead *head, int *val) {
    int ret_val = -1;
    if (head->number != 0) {
        struct LinkedListNode *ptr = head->start;
        head->start = head->start->next;
        head->number--;
        *val = ptr->val;
        free(ptr);
        ret_val = 0;
    }
    return ret_val;
}

void freeLinkedList(struct LinkedListHead *head) {
    struct LinkedListNode *ptr = head->start;
    struct LinkedListNode *prev;
    while(ptr != NULL) {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    free(head);
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int *prerequisitesColSizes) {
    if (numCourses == 0 || prerequisitesRowSize == 0)
        return true;
    struct LinkedListHead* queue = initLinkedListHead();
    bool adj_matrix[numCourses][numCourses];
    int prere_array[numCourses];
    for (int i = 0; i < numCourses; i++) {
        for (int j = 0; j < numCourses; j++) {
            adj_matrix[i][j] = false;
        }
        prere_array[i] = 0;
    }
    for (int i = 0; i < prerequisitesRowSize; i++) {
        adj_matrix[prerequisites[i][0]][prerequisites[i][1]] = true;
        prere_array[prerequisites[i][1]]++;
    }
    for (int i = 0; i < numCourses; i++) {
        if(prere_array[i] == 0) {
            offerLinkedList(queue,i);
            //printf("no prere: %d\n", i);
        }
    }
    int course_num;
    int count = 0;
    while(pollLinkedList(queue, &course_num) != -1) {
        //printf("course_num=%d\n", course_num);
        count++;
        for (int i = 0; i < numCourses; i++) {
            if (adj_matrix[course_num][i]) {
                prere_array[i]--;
                if (prere_array[i] == 0) {
                    //printf("Add dep: %d\n", i);
                    offerLinkedList(queue, i);
                }
            }
        }
    }
    return count == numCourses;
}

int main() {
    #define COL_SIZE 2
    int numCorses = 3;
    int ori_prere[][COL_SIZE] = {{1,0},{2,1}};
    int row_size = sizeof(ori_prere)/sizeof(ori_prere[0]);
    int *col_size = malloc(sizeof(int) * row_size);
    int **prere = malloc(sizeof(int *) * row_size);
    for (int i = 0; i < row_size; i++) {
        col_size[i] = COL_SIZE;
        prere[i] = malloc(sizeof(int) * col_size[i]);
        for (int j = 0; j < col_size[i]; j++) {
            prere[i][j] = ori_prere[i][j];
        }
    }
    if (canFinish(numCorses, prere, row_size, col_size))
        printf("true\n");
    else
        printf("false\n");
    free(col_size);
    for (int i = 0; i < row_size; i++)
        free(prere[i]);
    free(prere);
    return 0;
}