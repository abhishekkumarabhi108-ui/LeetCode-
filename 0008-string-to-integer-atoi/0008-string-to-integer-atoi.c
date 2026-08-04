#include <limits.h>

int myAtoi(char* s) {

    int i = 0;
    int sign = 1;
    int result = 0;

    // Step 1: Skip leading spaces
    while (s[i] == ' ') {
        i++;
    }

    // Step 2: Check sign
    if (s[i] == '-' || s[i] == '+') {

        if (s[i] == '-') {
            sign = -1;
        }

        i++;
    }

    // Step 3: Read digits
    while (s[i] >= '0' && s[i] <= '9') {

        int digit = s[i] - '0';

        // Check overflow before multiplication
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && digit > 7)) {

            if (sign == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }

        result = result * 10 + digit;

        i++;
    }

    return sign * result;
}