#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isPalindrome(char* s) {

    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {

        // Skip non-alphanumeric from left
        while (left < right && !isalnum((unsigned char)s[left])) {
            left++;
        }

        // Skip non-alphanumeric from right
        while (left < right && !isalnum((unsigned char)s[right])) {
            right--;
        }

        // Compare after converting to lowercase
        if (tolower((unsigned char)s[left]) !=
            tolower((unsigned char)s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}