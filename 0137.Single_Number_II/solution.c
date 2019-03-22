#include <stdio.h>
#include "../C_library/library.h"

int singleNumber(int* nums, int numsSize) {
    int tmp_a = 0, a = 0, b = 0;
    for (int i = 0; i < numsSize; i++) {
        tmp_a = (a&~b&~nums[i])|(~a&b&nums[i]);
        b = (~a&b&~nums[i])|(~a&~b&nums[i]);
        a = tmp_a;
    }
    return b;
}

int main() {
    int nums[] = {2,2,3,2};
    printf("singleNumber=%d\n", singleNumber(nums, ARRAY_SIZE(nums)));
    return 0;
}