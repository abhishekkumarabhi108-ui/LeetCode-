#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** findRepeatedDnaSequences(char* s, int* returnSize) {

    int len = strlen(s);
    *returnSize = 0;

    if (len < 10) {
        return NULL;
    }

    // 2-bit encoding:
    // A = 00, C = 01, G = 10, T = 11
    int map[26] = {0};
    map['C' - 'A'] = 1;
    map['G' - 'A'] = 2;
    map['T' - 'A'] = 3;

    int size = 1 << 20;          // 20 bits for 10 characters
    char** result = (char**)malloc((len - 9) * sizeof(char*));

    bool* seen = (bool*)calloc(size, sizeof(bool));
    bool* added = (bool*)calloc(size, sizeof(bool));

    int hash = 0;

    for (int i = 0; i < len; i++) {

        hash = ((hash << 2) | map[s[i] - 'A']) & ((1 << 20) - 1);

        if (i < 9)
            continue;

        if (!seen[hash]) {
            seen[hash] = true;
        } else if (!added[hash]) {

            result[*returnSize] = (char*)malloc(11);
            strncpy(result[*returnSize], s + i - 9, 10);
            result[*returnSize][10] = '\0';

            (*returnSize)++;
            added[hash] = true;
        }
    }

    free(seen);
    free(added);

    return result;
}