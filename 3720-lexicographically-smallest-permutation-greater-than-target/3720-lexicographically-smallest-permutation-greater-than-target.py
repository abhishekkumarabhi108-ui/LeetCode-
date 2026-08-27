class Solution:
    def lexGreaterPermutation(self, s, target):
        n = len(s)

        # Count characters of s
        freq = [0] * 26

        for ch in s:
            freq[ord(ch) - ord('a')] += 1

        # Try from right to left
        for i in range(n - 1, -1, -1):

            # Make a fresh frequency array
            count = freq[:]

            # Use target[0:i]
            possible = True

            for j in range(i):
                c = ord(target[j]) - ord('a')

                if count[c] == 0:
                    possible = False
                    break

                count[c] -= 1

            if not possible:
                continue

            # Find the smallest character greater than target[i]
            current = ord(target[i]) - ord('a')

            for c in range(current + 1, 26):
                if count[c] > 0:

                    # Put this character at position i
                    count[c] -= 1

                    answer = target[:i] + chr(c + ord('a'))

                    # Put remaining characters in sorted order
                    for k in range(26):
                        answer += chr(k + ord('a')) * count[k]

                    return answer

        return ""