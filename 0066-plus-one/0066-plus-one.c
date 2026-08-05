#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {

    // Start from last digit
    for (int i = digitsSize - 1; i >= 0; i--) {

        // If digit is less than 9, simply add 1
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }

        // 9 + 1 = 10, so current digit becomes 0
        digits[i] = 0;
    }

    // If all digits were 9
    int* result = (int*)calloc(digitsSize + 1, sizeof(int));

    result[0] = 1;

    *returnSize = digitsSize + 1;

    return result;
}