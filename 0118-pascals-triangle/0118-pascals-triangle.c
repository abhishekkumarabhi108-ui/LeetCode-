#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 */

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

    int** result = (int**)malloc(numRows * sizeof(int*));

    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    *returnSize = numRows;

    for (int i = 0; i < numRows; i++) {

        // Each row has i + 1 elements
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        // First and last element are always 1
        result[i][0] = 1;
        result[i][i] = 1;

        // Calculate middle elements
        for (int j = 1; j < i; j++) {
            result[i][j] =
                result[i - 1][j - 1] +
                result[i - 1][j];
        }
    }

    return result;
}