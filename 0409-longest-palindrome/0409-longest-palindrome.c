#include <string.h>

int longestPalindrome(char* s) {

    int count[52] = {0};

    // Count each character
    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] >= 'a' && s[i] <= 'z')
            count[s[i] - 'a']++;
        else
            count[26 + s[i] - 'A']++;
    }

    int length = 0;
    int hasOdd = 0;

    // Use pairs
    for (int i = 0; i < 52; i++) {

        length += (count[i] / 2) * 2;

        if (count[i] % 2 == 1)
            hasOdd = 1;
    }

    // One odd character can be placed in the center
    if (hasOdd)
        length++;

    return length;
}