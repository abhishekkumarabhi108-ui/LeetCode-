class Solution {
    public String lexPalindromicPermutation(String s, String target) {
        int n = s.length();

        // Count characters
        int[] freq = new int[26];

        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        // Check if a palindromic permutation is possible
        int oddCount = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddCount++;
                middle = (char) ('a' + i);
            }
        }

        if (oddCount > 1) {
            return "";
        }

        int halfLen = n / 2;

        // Frequency for the left half
        int[] halfFreq = new int[26];

        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        /*
         * First try to make the left half exactly equal
         * to target's first half.
         */
        int[] left = new int[halfLen];
        int[] remaining = halfFreq.clone();

        boolean canMatch = true;

        for (int i = 0; i < halfLen; i++) {
            int c = target.charAt(i) - 'a';

            if (remaining[c] == 0) {
                canMatch = false;
                break;
            }

            left[i] = c;
            remaining[c]--;
        }

        // If the left half can equal target's left half,
        // check the complete palindrome.
        if (canMatch) {
            String candidate = buildPalindrome(left, middle, n);

            if (candidate.compareTo(target) > 0) {
                return candidate;
            }
        }

        /*
         * We now need the smallest left half that is
         * lexicographically greater than target's left half.
         *
         * Try changing the rightmost possible position.
         */
        for (int i = halfLen - 1; i >= 0; i--) {

            int[] count = halfFreq.clone();

            // Use target[0 ... i-1]
            boolean possible = true;

            for (int j = 0; j < i; j++) {
                int c = target.charAt(j) - 'a';

                if (count[c] == 0) {
                    possible = false;
                    break;
                }

                count[c]--;
            }

            if (!possible) {
                continue;
            }

            // At position i, choose the smallest
            // character greater than target[i].
            int current = target.charAt(i) - 'a';

            for (int c = current + 1; c < 26; c++) {

                if (count[c] == 0) {
                    continue;
                }

                count[c]--;

                int[] newLeft = new int[halfLen];

                // Copy prefix
                for (int j = 0; j < i; j++) {
                    newLeft[j] = target.charAt(j) - 'a';
                }

                // Put the smallest greater character
                newLeft[i] = c;

                // Fill the rest with smallest characters
                int pos = i + 1;

                for (int x = 0; x < 26; x++) {
                    while (count[x] > 0) {
                        newLeft[pos++] = x;
                        count[x]--;
                    }
                }

                return buildPalindrome(newLeft, middle, n);
            }
        }

        return "";
    }

    private String buildPalindrome(int[] left, char middle, int n) {
        StringBuilder sb = new StringBuilder();

        // Left half
        for (int c : left) {
            sb.append((char) ('a' + c));
        }

        // Middle character
        if (n % 2 == 1) {
            sb.append(middle);
        }

        // Right half
        for (int i = left.length - 1; i >= 0; i--) {
            sb.append((char) ('a' + left[i]));
        }

        return sb.toString();
    }
}