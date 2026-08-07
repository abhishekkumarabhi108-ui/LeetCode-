#include <string.h>
#include <stdlib.h>

int closestTarget(char** words, int wordsSize, char* target, int startIndex) {

    int ans = wordsSize + 1;

    for (int i = 0; i < wordsSize; i++) {

        if (strcmp(words[i], target) == 0) {

            int dist = abs(i - startIndex);

            if (wordsSize - dist < dist)
                dist = wordsSize - dist;

            if (dist < ans)
                ans = dist;
        }
    }

    return (ans == wordsSize + 1) ? -1 : ans;
}