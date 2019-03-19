#include <stdio.h>
#include "../C_library/library.h"

#define swap(a,b) \
do {  \
    int tmp = a;\
    a = b; \
    b = tmp; \
}while(0);

enum {
    RED = 0,
    WHITE = 1,
    BLUE = 2,
    TOTAL_COLOR
};

void sortColors(int* nums, int numsSize) {
    int last_pos[TOTAL_COLOR];
    int count[TOTAL_COLOR] = {0};
    for (int i = 0; i < TOTAL_COLOR; i++)
        last_pos[i] = -1;
    for (int i = 0; i < numsSize; i++) {
        last_pos[TOTAL_COLOR-1] = i;
        count[nums[i]]++;
        for (int j = nums[i]; j < TOTAL_COLOR-1; j++) {
            last_pos[j]++;
            if (count[j] == 0)
                continue;
            //printf("i=%d j=%d nums[j]=%d last_pos[j]=%d\n", i, j, nums[j], last_pos[j]);
            //printf("nums[%d]=%d, nums[%d]=%d\n", last_pos[j], nums[last_pos[j]], i, nums[i]);
            swap(nums[last_pos[j]], nums[i]);
            //printf("nums[%d]=%d, nums[%d]=%d\n", last_pos[j], nums[last_pos[j]], i, nums[i]);
        }
    }
}

int main() {
#if 0
    int nums[] = {2,0,2,1,1,0};
#elif 0
    int nums[] = {2,1,0,2,1,0};
#elif 0
    int nums[] = {2,0};
#elif 1
    int nums[] = {0,1,2,0,1,2};
#endif
    int numsSize = ARRAY_SIZE(nums);
    sortColors(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}