#include <stdio.h>
#include <stdlib.h>

char* toBinary(int n) {
    char temp[20];
    int i = 0;

    while (n > 0) {
        temp[i++] = (n % 2) + '0';
        n /= 2;
    }

    char* result = (char*)malloc((i + 1) * sizeof(char));

    for (int j = 0; j < i; j++) {
        result[j] = temp[i - j - 1];
    }

    result[i] = '\0';

    return result;
}

char* convertDateToBinary(char* date) {

    int year, month, day;

    sscanf(date, "%d-%d-%d", &year, &month, &day);

    char* y = toBinary(year);
    char* m = toBinary(month);
    char* d = toBinary(day);

    char* result = (char*)malloc(50 * sizeof(char));

    sprintf(result, "%s-%s-%s", y, m, d);

    free(y);
    free(m);
    free(d);

    return result;
}