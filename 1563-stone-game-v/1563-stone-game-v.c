#include <stdlib.h>

int stoneGameV(int* stoneValue, int n) {

    int prefix[501] = {0};
    int dp[501][501] = {0};

    // Prefix sum
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    // Length of subarray
    for (int len = 2; len <= n; len++) {

        for (int i = 0; i + len <= n; i++) {

            int j = i + len - 1;

            // Try every split
            for (int k = i; k < j; k++) {

                int left = prefix[k + 1] - prefix[i];
                int right = prefix[j + 1] - prefix[k + 1];

                if (left < right) {

                    int score = left + dp[i][k];

                    if (score > dp[i][j])
                        dp[i][j] = score;
                }
                else if (right < left) {

                    int score = right + dp[k + 1][j];

                    if (score > dp[i][j])
                        dp[i][j] = score;
                }
                else {

                    int score1 = left + dp[i][k];
                    int score2 = right + dp[k + 1][j];

                    if (score1 > dp[i][j])
                        dp[i][j] = score1;

                    if (score2 > dp[i][j])
                        dp[i][j] = score2;
                }
            }
        }
    }

    return dp[0][n - 1];
}