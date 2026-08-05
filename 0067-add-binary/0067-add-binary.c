#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {

    int i = strlen(a) - 1;
    int j = strlen(b) - 1;

    int maxLength = (i > j ? i : j) + 2;

    char* result = (char*)malloc((maxLength + 1) * sizeof(char));

    int k = maxLength - 1;
    int carry = 0;

    result[maxLength] = '\0';

    while (i >= 0 || j >= 0 || carry) {

        int sum = carry;

        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }

        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }

        result[k] = (sum % 2) + '0';
        carry = sum / 2;

        k--;
    }

    // Move result to beginning
    int start = k + 1;
    int index = 0;

    while (start < maxLength) {
        result[index++] = result[start++];
    }

    result[index] = '\0';

    return result;
}