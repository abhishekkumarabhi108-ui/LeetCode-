#include <stdbool.h>

bool checkRecord(char* s) {

    int absent = 0;
    int late = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] == 'A') {
            absent++;

            if (absent >= 2)
                return false;

            late = 0;
        }
        else if (s[i] == 'L') {
            late++;

            if (late >= 3)
                return false;
        }
        else {
            // P resets consecutive late count
            late = 0;
        }
    }

    return true;
}