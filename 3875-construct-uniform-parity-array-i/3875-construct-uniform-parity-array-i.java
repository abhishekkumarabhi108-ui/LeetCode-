class Solution {
    public boolean uniformArray(int[] nums1) {
        
        // If all elements are already even,
        // we can simply keep them as they are.
        boolean allEven = true;

        for (int num : nums1) {
            if (num % 2 != 0) {
                allEven = false;
                break;
            }
        }

        if (allEven) {
            return true;
        }

        // If all elements are already odd,
        // we can simply keep them as they are.
        boolean allOdd = true;

        for (int num : nums1) {
            if (num % 2 == 0) {
                allOdd = false;
                break;
            }
        }

        if (allOdd) {
            return true;
        }

        // If the array contains both even and odd numbers,
        // we can make every element odd by subtracting
        // an element of opposite parity.
        //
        // Therefore, it is always possible.
        return true;
    }
}