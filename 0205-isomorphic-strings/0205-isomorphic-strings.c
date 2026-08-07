#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char* s, char* t) {

    int mapST[256] = {0};
    int mapTS[256] = {0};

    int n = strlen(s);

    for (int i = 0; i < n; i++) {

        unsigned char c1 = s[i];
        unsigned char c2 = t[i];

        // If no mapping exists, create one
        if (mapST[c1] == 0 && mapTS[c2] == 0) {
            mapST[c1] = c2 + 1;
            mapTS[c2] = c1 + 1;
        }
        // Mapping mismatch
        else if (mapST[c1] != c2 + 1 ||
                 mapTS[c2] != c1 + 1) {
            return false;
        }
    }

    return true;
}