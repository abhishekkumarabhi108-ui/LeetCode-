#include <stdlib.h>

// Comparator for qsort
int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

// Binary search
int binarySearch(int* arr, int size, int target) {

    int left = 0;
    int right = size - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {

    *returnSize = arrSize;

    if (arrSize == 0) {
        return NULL;
    }

    // Make copy of original array
    int* sorted = (int*)malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++) {
        sorted[i] = arr[i];
    }

    // Sort the copied array
    qsort(sorted, arrSize, sizeof(int), compare);

    // Remove duplicates
    int uniqueCount = 0;

    for (int i = 0; i < arrSize; i++) {

        if (i == 0 || sorted[i] != sorted[i - 1]) {
            sorted[uniqueCount] = sorted[i];
            uniqueCount++;
        }
    }

    // Create result
    int* result = (int*)malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++) {

        int index = binarySearch(sorted, uniqueCount, arr[i]);

        // Rank starts from 1
        result[i] = index + 1;
    }

    free(sorted);

    return result;
}