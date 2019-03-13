#include <stdio.h>
#include <stdlib.h>

int compare(const void *num1, const void *num2) {
    if (*(int *)num1 < *(int *)num2) {
        return 1;
    } else if (*(int *)num1 > *(int *)num2) {
        return -1;
    } else {
        return 0;
    }
}

int hIndex(int* citations, int citationsSize) {
    if (citationsSize == 0) return 0;
    qsort(citations, citationsSize, sizeof(citations[0]), compare);
    for (int i = 0; i < citationsSize; i++) {
        if (i+1 > citations[i])
            return i;
    }
    return citationsSize;
}

int main() {
    //int citations[] = {3,0,6,1,5};
    //int citations[] = {100};
    int citations[] = {0};
    printf("h-index: %d\n", hIndex(citations, sizeof(citations)/sizeof(citations[0])));
    return 0;
}