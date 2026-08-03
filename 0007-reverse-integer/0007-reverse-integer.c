#include <limits.h>

int reverse(int x) {

    int result = 0;

    while (x != 0) {

        int digit = x % 10;
        x = x / 10;

        // Positive overflow check
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && digit > 7)) {
            return 0;
        }

        // Negative overflow check
        if (result < INT_MIN / 10 ||
            (result == INT_MIN / 10 && digit < -8)) {
            return 0;
        }

        result = result * 10 + digit;
    }

    return result;
}