#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    int *stack;
    int max_size;
    int cur_ptr;
    int *min_num;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *ret_stack = malloc(sizeof(MinStack));
    ret_stack->stack = malloc(sizeof(int) * maxSize);
    ret_stack->max_size = maxSize;
    ret_stack->cur_ptr = 0;
    ret_stack->min_num = malloc(sizeof(int) * maxSize);
    return ret_stack;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->cur_ptr >= obj->max_size)
        return;
    obj->stack[obj->cur_ptr] = x;
    if (obj->cur_ptr != 0)
        obj->min_num[obj->cur_ptr] = fmin(x, obj->min_num[obj->cur_ptr-1]);
    else
        obj->min_num[obj->cur_ptr] = x;
    obj->cur_ptr++;
}

void minStackPop(MinStack* obj) {
    if (obj->cur_ptr > 0)
        obj->cur_ptr--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->cur_ptr-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min_num[obj->cur_ptr-1];
}

void minStackFree(MinStack* obj) {
    if (obj == NULL)
        return;
    free(obj->stack);
    free(obj);
}

int main() {
    int maxSize = 5;
    MinStack* obj = minStackCreate(maxSize);
    minStackPush(obj, 11);
    minStackPush(obj, 12);
    minStackPush(obj, 13);
    minStackPop(obj);
    int top = minStackTop(obj);
    int min = minStackGetMin(obj);
    printf("top=%d, min=%d\n", top, min);
    minStackFree(obj);
}