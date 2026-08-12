#include <stdlib.h>

char* toHex(int num) {
    
    char* hex = "0123456789abcdef";
    char* result = (char*)malloc(9);
    
    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    unsigned int n = (unsigned int)num;
    int i = 0;

    while (n > 0) {
        result[i++] = hex[n & 15];
        n >>= 4;
    }

    result[i] = '\0';

    // Reverse the result
    for (int left = 0, right = i - 1; left < right; left++, right--) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
    }

    return result;
}