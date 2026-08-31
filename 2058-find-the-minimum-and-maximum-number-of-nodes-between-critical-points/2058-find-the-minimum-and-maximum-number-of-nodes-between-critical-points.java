class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {

        int first = -1;
        int previous = -1;

        int minDistance = Integer.MAX_VALUE;
        int maxDistance = -1;

        int index = 1;

        ListNode prev = head;
        ListNode curr = head.next;

        while (curr.next != null) {

            ListNode next = curr.next;

            // Check if current node is a critical point
            boolean isCritical =
                    (curr.val > prev.val && curr.val > next.val) ||
                    (curr.val < prev.val && curr.val < next.val);

            if (isCritical) {

                // First critical point
                if (first == -1) {
                    first = index;
                }

                // If this is not the first critical point
                if (previous != -1) {
                    minDistance = Math.min(
                            minDistance,
                            index - previous
                    );

                    maxDistance = index - first;
                }

                previous = index;
            }

            prev = curr;
            curr = next;
            index++;
        }

        // Fewer than two critical points
        if (minDistance == Integer.MAX_VALUE) {
            return new int[]{-1, -1};
        }

        return new int[]{minDistance, maxDistance};
    }
}