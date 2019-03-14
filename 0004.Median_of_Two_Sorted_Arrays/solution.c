#include <stdio.h>
#include <stdbool.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total_len = nums1Size + nums2Size;
    int nums1_ptr = 0, nums2_ptr = 0;
    bool average_flag = (total_len % 2 == 0);
    int medium = total_len / 2;
    double last_val, current_val;
    for (int i = 0; i <= medium; i++) {
        last_val = current_val;
        if (nums2_ptr >= nums2Size) {
            current_val = nums1[nums1_ptr];
            nums1_ptr++;
        } else if (nums1_ptr >= nums1Size) {
            current_val = nums2[nums2_ptr];
            nums2_ptr++;
        } else {
            if (nums1[nums1_ptr] <= nums2[nums2_ptr]) {
                current_val = nums1[nums1_ptr];
                nums1_ptr++;
            } else {
                current_val = nums2[nums2_ptr];
                nums2_ptr++;
            }
        }
    }
    if (average_flag) {
        return (current_val + last_val) / 2;
    } else {
        return current_val;
    }
}

int main () {
#if 0
    int nums1[] = {1, 3};
    int nums2[] = {2};
    printf("findMedianSortedArrays: %f\n", findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(nums1[0]), nums2, sizeof(nums2)/sizeof(nums2[0])));
#else
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};
    printf("findMedianSortedArrays: %f\n", findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(nums1[0]), nums2, sizeof(nums2)/sizeof(nums2[0])));
#endif
#if 0
    int *nums1 = NULL;
    int nums2[] = {1};
    printf("findMedianSortedArrays: %f\n", findMedianSortedArrays(nums1, 0, nums2, sizeof(nums2)/sizeof(nums2[0])));
#endif
#if 0
    int nums1[] = {2};
    int *nums2 = NULL;
    printf("findMedianSortedArrays: %f\n", findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(nums1[0]), nums2, 0));
#endif
    return 0;
}