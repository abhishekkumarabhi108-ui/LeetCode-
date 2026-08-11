#include <stdlib.h>

/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {

    int* row = (int*)malloc((rowIndex + 1) * sizeof(int));

    *returnSize = rowIndex + 1;

    row[0] = 1;

    for (int i = 1; i <= rowIndex; i++) {

        row[i] = 1;

        // Update from right to left
        for (int j = i - 1; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}