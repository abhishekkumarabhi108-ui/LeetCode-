#include <stdbool.h>
#include <string.h>

bool isCircularSentence(char* sentence) {

    int n = strlen(sentence);

    // Check first and last character
    if (sentence[0] != sentence[n - 1]) {
        return false;
    }

    // Check every space
    for (int i = 1; i < n - 1; i++) {

        if (sentence[i] == ' ') {

            if (sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }
    }

    return true;
}