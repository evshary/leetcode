#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int add_one = 1;
    for (int i = digitsSize-1; i >= 0; i--) {
        if (add_one != 1)
            break;
        if (digits[i] == 9) {
            digits[i] = 0;
            add_one = 1;
        } else {
            digits[i]++;
            add_one = 0;
        }
    }
    *returnSize = digitsSize + add_one;
    int *return_digits = malloc(sizeof(int) * (*returnSize));
    if (add_one)
        return_digits[0] = add_one;
    for (int i = add_one, j = 0; i < *returnSize; i++, j++)
        return_digits[i] = digits[j];
    return return_digits;
}

int main() {
    //int digits[] = {1,2,3};
    int digits[] = {9,9,9};
    int returnSize;
    int *returnNums = plusOne(digits, sizeof(digits)/sizeof(digits[0]), &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", returnNums[i]);
    }
    printf("\n");
    return 0;
}