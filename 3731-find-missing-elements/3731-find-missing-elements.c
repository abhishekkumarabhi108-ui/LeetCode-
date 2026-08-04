#include <stdlib.h>
#include <stdbool.h>

int* findMissingElements(int* nums, int numsSize, int* returnSize) {

    bool present[101] = {false};

    int min = nums[0];
    int max = nums[0];

    // Find min, max and mark elements present
    for (int i = 0; i < numsSize; i++) {

        present[nums[i]] = true;

        if (nums[i] < min) {
            min = nums[i];
        }

        if (nums[i] > max) {
            max = nums[i];
        }
    }

    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    // Find missing numbers
    for (int i = min; i <= max; i++) {

        if (!present[i]) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }

    return result;
}
