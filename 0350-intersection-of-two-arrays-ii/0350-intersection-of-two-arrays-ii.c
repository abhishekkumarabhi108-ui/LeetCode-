#include <stdlib.h>

int* intersect(int* nums1, int nums1Size,
               int* nums2, int nums2Size,
               int* returnSize) {

    int count[1001] = {0};

    int size = nums1Size < nums2Size ? nums1Size : nums2Size;

    int* result = (int*)malloc(size * sizeof(int));

    *returnSize = 0;

    // Count elements in nums1
    for (int i = 0; i < nums1Size; i++) {
        count[nums1[i]]++;
    }

    // Find intersection using nums2
    for (int i = 0; i < nums2Size; i++) {

        if (count[nums2[i]] > 0) {

            result[*returnSize] = nums2[i];
            (*returnSize)++;

            count[nums2[i]]--;
        }
    }

    return result;
}