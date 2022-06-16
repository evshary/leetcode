#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int ret_max = 0, wide_size, tmp_max;
    int i, j;
    for (i = 0; i < heightSize; i++) {
        for (j = 0; j < i; j++) {
            if (height[j] >= height[i])
                break;
        }
        wide_size = i - j;
        for (j = heightSize-1; j > i; j--) {
            if (height[j] >= height[i])
                break;
        }
        wide_size = ((j-i) > wide_size)?(j-i):wide_size;
        tmp_max = wide_size * height[i];
        ret_max = (ret_max > tmp_max)?ret_max:tmp_max;
    }
    return ret_max;
}

int main()
{
    int height[] = {1,8,6,2,5,4,8,3,7};
    printf("maxArea=%d\r\n", maxArea(height, sizeof(height)/sizeof(int)));
    return 0;
}