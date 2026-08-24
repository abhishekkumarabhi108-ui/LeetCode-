long long stoneGameVIII(int* stones, int n) {

    long long sum = 0;

    // Total prefix sum
    for (int i = 0; i < n; i++)
        sum += stones[i];

    long long best = sum;

    // Work backwards
    for (int i = n - 2; i >= 1; i--) {

        sum -= stones[i + 1];

        if (sum - best > best)
            best = sum - best;
    }

    return best;
}