int subarraySum(int* nums, int numsSize) {

    int totalSum = 0;

    for (int i = 0; i < numsSize; i++) {

        // Calculate starting index
        int start = i - nums[i];

        if (start < 0) {
            start = 0;
        }

        // Add elements from start to i
        for (int j = start; j <= i; j++) {
            totalSum += nums[j];
        }
    }

    return totalSum;
}