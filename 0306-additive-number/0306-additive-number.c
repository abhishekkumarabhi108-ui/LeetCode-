#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool dfs(char *num, int start, unsigned long long first,
         unsigned long long second, int count) {

    int len = strlen(num);

    if (start == len)
        return count >= 3;

    unsigned long long current = 0;

    for (int i = start; i < len; i++) {

        // Leading zero is not allowed
        if (i > start && num[start] == '0')
            break;

        current = current * 10 + (num[i] - '0');

        if (count >= 2) {

            unsigned long long sum = first + second;

            if (current < sum)
                continue;

            if (current > sum)
                break;
        }

        if (dfs(num, i + 1, second, current, count + 1))
            return true;
    }

    return false;
}

bool isAdditiveNumber(char* num) {

    return dfs(num, 0, 0, 0, 0);
}