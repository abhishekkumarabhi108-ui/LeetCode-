#include <stdbool.h>

bool predictTheWinner(int* nums, int numsSize) {

    int dp[20][20];

    // One element
    for (int i = 0; i < numsSize; i++) {
        dp[i][i] = nums[i];
    }

    // Subarray length
    for (int len = 2; len <= numsSize; len++) {

        for (int i = 0; i + len <= numsSize; i++) {

            int j = i + len - 1;

            int left = nums[i] - dp[i + 1][j];
            int right = nums[j] - dp[i][j - 1];

            if (left > right)
                dp[i][j] = left;
            else
                dp[i][j] = right;
        }
    }

    return dp[0][numsSize - 1] >= 0;
}