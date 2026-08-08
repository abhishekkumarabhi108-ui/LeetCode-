#include <string.h>

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' ||
           c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' ||
           c == 'O' || c == 'U';
}

char* reverseVowels(char* s) {

    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {

        // Find vowel from left
        while (left < right && !isVowel(s[left])) {
            left++;
        }

        // Find vowel from right
        while (left < right && !isVowel(s[right])) {
            right--;
        }

        // Swap vowels
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }

    return s;
}