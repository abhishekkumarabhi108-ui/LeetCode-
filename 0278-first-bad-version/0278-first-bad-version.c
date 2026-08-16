// The API is already provided by LeetCode
// bool isBadVersion(int version);

int firstBadVersion(int n) {

    int left = 1;
    int right = n;

    while (left < right) {

        int mid = left + (right - left) / 2;

        if (isBadVersion(mid)) {
            // First bad version is mid or before it
            right = mid;
        } else {
            // First bad version is after mid
            left = mid + 1;
        }
    }

    return left;
}