#include <stdlib.h>
#include <string.h>

char* convertToTitle(int columnNumber) {

    char temp[20];
    int index = 0;

    while (columnNumber > 0) {

        columnNumber--;

        temp[index++] = 'A' + (columnNumber % 26);

        columnNumber /= 26;
    }

    // Reverse the characters
    char* result = (char*)malloc((index + 1) * sizeof(char));

    for (int i = 0; i < index; i++) {
        result[i] = temp[index - 1 - i];
    }

    result[index] = '\0';

    return result;
}