#include <stdlib.h>

int* resultArray(int* nums, int numsSize, int* returnSize) {

    int* arr1 = malloc(numsSize * sizeof(int));
    int* arr2 = malloc(numsSize * sizeof(int));
    int* result = malloc(numsSize * sizeof(int));

    int n1 = 0, n2 = 0;

    arr1[n1++] = nums[0];
    arr2[n2++] = nums[1];

    for (int i = 2; i < numsSize; i++) {

        if (arr1[n1 - 1] > arr2[n2 - 1])
            arr1[n1++] = nums[i];
        else
            arr2[n2++] = nums[i];
    }

    int k = 0;

    for (int i = 0; i < n1; i++)
        result[k++] = arr1[i];

    for (int i = 0; i < n2; i++)
        result[k++] = arr2[i];

    *returnSize = numsSize;

    free(arr1);
    free(arr2);

    return result;
}