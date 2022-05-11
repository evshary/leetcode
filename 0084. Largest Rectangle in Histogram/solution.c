#include <stdio.h>
#include <math.h>

#define LEFT_RIGHT_WAY 0
#define STACK_WAY      1

#if LEFT_RIGHT_WAY
int largestRectangleArea(int* heights, int heightsSize) {
    if (heightsSize <= 0)
        return 0;
    int left_higher[heightsSize];
    int right_higher[heightsSize];
    int last_ptr;
    int max_area = 0;
    for (int i = 0; i < heightsSize; i++) {
        left_higher[i] = 0;
        last_ptr = i - 1;
        while (last_ptr >= 0) {
            if (heights[last_ptr] >= heights[i]) {
                //printf("last_ptr=%d left_higher[last_ptr]=%d\n", last_ptr, left_higher[last_ptr]);
                left_higher[i] += left_higher[last_ptr] + 1;
                last_ptr -= left_higher[last_ptr] + 1;
            } else {
                break;
            }
        }
    }
    for (int i = heightsSize-1; i >= 0; i--) {
        right_higher[i] = 0;
        last_ptr = i + 1;
        while (last_ptr < heightsSize) {
            if (heights[last_ptr] >= heights[i]) {
                //printf("last_ptr=%d right_higher[last_ptr]=%d\n", last_ptr, right_higher[last_ptr]);
                right_higher[i] += right_higher[last_ptr] + 1;
                last_ptr += right_higher[last_ptr] + 1;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < heightsSize; i++) {
        max_area = fmax(max_area, (right_higher[i] + left_higher[i] + 1) * heights[i]);
        //printf("i=%d, left_higher[i]=%d, right_higher[i]=%d, heights[i]=%d, max_area=%d\n", i, left_higher[i], right_higher[i], heights[i], max_area);
    }
    return max_area;
}
#endif /*LEFT_RIGHT_WAY*/

#if STACK_WAY
int largestRectangleArea(int* heights, int heightsSize) {
    int newSize = heightsSize+2;
    int new_heights[newSize];
    for (int i = 0; i < heightsSize; i++){
        new_heights[i+1] = heights[i];
    }
    new_heights[0] = new_heights[newSize - 1] = 0;
    int stack[newSize];
    int next_ptr = 0;
    int max_size = 0;
    int cur_weight, cur_height;
    for (int i = 0; i < newSize; i++) {
        //printf(">> i=%d new_heights[i]=%d\n", i, new_heights[i]);
        while (next_ptr > 1 && new_heights[stack[next_ptr-1]] >= new_heights[i]) {
            //printf("next_ptr=%d, stack[next_ptr-1]=%d\n", next_ptr, stack[next_ptr-1]);
            cur_height = new_heights[stack[--next_ptr]]; // get the height and pop the stack
            cur_weight = i - stack[next_ptr-1] - 1;
            //printf("cur_height=%d cur_weight=%d\n", cur_height, cur_weight);
            max_size = fmax(max_size, cur_weight * cur_height);
        }
        stack[next_ptr++] = i; // push stack
    }
    return max_size;
}
#endif /*STACK_WAY*/

int main () {
    //int heights[] = {1,2,3};
    //int heights[] = {2,1,5,6,2,3};
    //int heights[] = {4,2,0,3,2,4,3,4};
    int heights[] = {3,6,5,7,4,8,1,0};
    printf("largestRectangleArea=%d\n", largestRectangleArea(heights, sizeof(heights)/sizeof(heights[0])));
    return 0;
}