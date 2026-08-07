#include <string.h>
#include <stdbool.h>

int maximumValue(char** strs, int strsSize) {

    int maxValue = 0;

    for (int i = 0; i < strsSize; i++) {

        bool isNumber = true;
        int value = 0;
        int len = strlen(strs[i]);

        for (int j = 0; j < len; j++) {

            if (strs[i][j] < '0' || strs[i][j] > '9') {
                isNumber = false;
                break;
            }

            value = value * 10 + (strs[i][j] - '0');
        }

        if (!isNumber) {
            value = len;
        }

        if (value > maxValue) {
            maxValue = value;
        }
    }

    return maxValue;
}