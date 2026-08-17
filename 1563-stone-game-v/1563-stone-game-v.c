#include <stdlib.h>

int stoneGameV(int* stoneValue, int stoneValueSize) {

    int n = stoneValueSize;

    // Prefix sum
    int* prefix = (int*)malloc((n + 1) * sizeof(int));

    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    // dp[i][j] = maximum score from i to j
    int dp[500][500] = {0};

    // Length of the subarray
    for (int len = 2; len <= n; len++) {

        for (int i = 0; i + len <= n; i++) {

            int j = i + len - 1;

            // Try every possible split
            for (int k = i; k < j; k++) {

                int left = prefix[k + 1] - prefix[i];
                int right = prefix[j + 1] - prefix[k + 1];

                if (left < right) {
                    int value = left + dp[i][k];

                    if (value > dp[i][j])
                        dp[i][j] = value;
                }
                else if (right < left) {
                    int value = right + dp[k + 1][j];

                    if (value > dp[i][j])
                        dp[i][j] = value;
                }
                else {
                    int value1 = left + dp[i][k];
                    int value2 = right + dp[k + 1][j];

                    if (value1 > dp[i][j])
                        dp[i][j] = value1;

                    if (value2 > dp[i][j])
                        dp[i][j] = value2;
                }
            }
        }
    }

    int answer = dp[0][n - 1];

    free(prefix);

    return answer;
}