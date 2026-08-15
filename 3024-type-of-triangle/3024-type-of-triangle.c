char* triangleType(int* nums, int numsSize) {

    // Check if triangle is possible
    if (nums[0] + nums[1] <= nums[2] ||
        nums[0] + nums[2] <= nums[1] ||
        nums[1] + nums[2] <= nums[0]) {
        return "none";
    }

    // All sides equal
    if (nums[0] == nums[1] && nums[1] == nums[2]) {
        return "equilateral";
    }

    // Any two sides equal
    if (nums[0] == nums[1] ||
        nums[1] == nums[2] ||
        nums[0] == nums[2]) {
        return "isosceles";
    }

    // All sides different
    return "scalene";
}