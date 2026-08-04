#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 */

int** shiftGrid(int** grid, int gridSize, int* gridColSize,
                int k, int* returnSize, int** returnColumnSizes) {

    int m = gridSize;
    int n = gridColSize[0];
    int total = m * n;

    // Avoid unnecessary shifts
    k = k % total;

    // Allocate result grid
    int** result = (int**)malloc(m * sizeof(int*));

    *returnColumnSizes = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    // Shift every element
    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            // Current 2D position -> 1D index
            int oldIndex = i * n + j;

            // New position after k shifts
            int newIndex = (oldIndex + k) % total;

            // Convert 1D index -> 2D position
            int newRow = newIndex / n;
            int newCol = newIndex % n;

            result[newRow][newCol] = grid[i][j];
        }
    }

    *returnSize = m;

    return result;
}