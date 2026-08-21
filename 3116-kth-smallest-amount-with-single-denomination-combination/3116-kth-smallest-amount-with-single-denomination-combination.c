#include <stdlib.h>

long long gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

long long count(long long x, int* coins, int n) {
    long long total = 0;

    for (int mask = 1; mask < (1 << n); mask++) {

        long long multiple = 1;
        int bits = 0;
        int valid = 1;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                bits++;

                multiple = lcm(multiple, coins[i]);

                if (multiple > x) {
                    valid = 0;
                    break;
                }
            }
        }

        if (!valid)
            continue;

        if (bits % 2 == 1)
            total += x / multiple;
        else
            total -= x / multiple;
    }

    return total;
}

long long findKthSmallest(int* coins, int coinsSize, long long k) {

    long long left = 1;
    long long right = 1LL * coins[0] * k;

    while (left < right) {

        long long mid = left + (right - left) / 2;

        if (count(mid, coins, coinsSize) >= k)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}