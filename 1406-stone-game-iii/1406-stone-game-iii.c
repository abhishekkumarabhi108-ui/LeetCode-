#include <stdlib.h>

char* stoneGameIII(int* stoneValue, int n) {

    int* dp = (int*)calloc(n + 1, sizeof(int));

    // Start from the end
    for (int i = n - 1; i >= 0; i--) {

        int sum = 0;
        dp[i] = -1000000000;

        // Take 1, 2 or 3 stones
        for (int j = 0; j < 3 && i + j < n; j++) {

            sum += stoneValue[i + j];

            int score = sum - dp[i + j + 1];

            if (score > dp[i])
                dp[i] = score;
        }
    }

    int result = dp[0];

    free(dp);

    if (result > 0)
        return "Alice";

    if (result < 0)
        return "Bob";

    return "Tie";
}