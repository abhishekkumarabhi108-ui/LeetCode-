#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int threeSumClosest(int* nums, int numsSize, int target) {

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Initialize with first three elements
    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            // Update closest sum
            if (abs(target - sum) < abs(target - closestSum)) {
                closestSum = sum;
            }

            // Exact target found
            if (sum == target) {
                return sum;
            }

            // Need a larger sum
            if (sum < target) {
                left++;
            }

            // Need a smaller sum
            else {
                right--;
            }
        }
    }

    return closestSum;
}