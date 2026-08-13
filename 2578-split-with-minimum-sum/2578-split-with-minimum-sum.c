#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int splitNum(int num) {

    int digits[10];
    int n = 0;

    // Extract digits
    while (num > 0) {
        digits[n++] = num % 10;
        num /= 10;
    }

    // Sort digits
    qsort(digits, n, sizeof(int), compare);

    int num1 = 0;
    int num2 = 0;

    // Distribute digits alternately
    for (int i = 0; i < n; i++) {

        if (i % 2 == 0)
            num1 = num1 * 10 + digits[i];
        else
            num2 = num2 * 10 + digits[i];
    }

    return num1 + num2;
}