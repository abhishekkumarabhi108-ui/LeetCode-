#include <stdlib.h>

/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size,
                  int* nums2, int nums2Size,
                  int* returnSize) {

    int seen[1001] = {0};

    int* result = (int*)malloc(1001 * sizeof(int));
    *returnSize = 0;

    // Mark numbers from nums1
    for (int i = 0; i < nums1Size; i++) {
        seen[nums1[i]] = 1;
    }

    // Check numbers from nums2
    for (int i = 0; i < nums2Size; i++) {
        if (seen[nums2[i]] == 1) {
            result[*returnSize] = nums2[i];
            (*returnSize)++;

            // Avoid duplicate result
            seen[nums2[i]] = 0;
        }
    }

    return result;
}