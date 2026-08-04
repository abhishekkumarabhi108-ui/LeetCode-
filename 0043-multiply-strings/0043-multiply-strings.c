#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {

    int n1 = strlen(num1);
    int n2 = strlen(num2);

    // Handle zero
    if ((n1 == 1 && num1[0] == '0') ||
        (n2 == 1 && num2[0] == '0')) {

        char* zero = (char*)malloc(2 * sizeof(char));
        zero[0] = '0';
        zero[1] = '\0';

        return zero;
    }

    int size = n1 + n2;

    // Array to store multiplication result
    int* result = (int*)calloc(size, sizeof(int));

    // Multiply digits
    for (int i = n1 - 1; i >= 0; i--) {

        for (int j = n2 - 1; j >= 0; j--) {

            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';

            int product = digit1 * digit2;

            int pos1 = i + j;
            int pos2 = i + j + 1;

            int sum = product + result[pos2];

            result[pos2] = sum % 10;
            result[pos1] += sum / 10;
        }
    }

    // Convert result array to string
    char* answer = (char*)malloc((size + 1) * sizeof(char));

    int index = 0;
    int i = 0;

    // Skip leading zeros
    while (i < size && result[i] == 0) {
        i++;
    }

    while (i < size) {
        answer[index++] = result[i] + '0';
        i++;
    }

    answer[index] = '\0';

    free(result);

    return answer;
}