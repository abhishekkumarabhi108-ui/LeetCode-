#include <stdbool.h>

bool sumGame(char* num) {

    int n = 0;
    while (num[n] != '\0')
        n++;

    int half = n / 2;

    int leftSum = 0, rightSum = 0;
    int leftQ = 0, rightQ = 0;

    for (int i = 0; i < half; i++) {
        if (num[i] == '?')
            leftQ++;
        else
            leftSum += num[i] - '0';
    }

    for (int i = half; i < n; i++) {
        if (num[i] == '?')
            rightQ++;
        else
            rightSum += num[i] - '0';
    }

    // If number of ? is odd, Alice wins
    if ((leftQ + rightQ) % 2 == 1)
        return true;

    int diff = leftSum - rightSum;
    int qDiff = leftQ - rightQ;

    // Bob can make the sums equal only in this case
    return diff + (qDiff / 2) * 9 != 0;
}