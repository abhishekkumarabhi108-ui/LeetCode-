int similarPairs(char** words, int wordsSize) {

    int masks[100];
    int count = 0;

    // Create bitmask for each word
    for (int i = 0; i < wordsSize; i++) {

        int mask = 0;

        for (int j = 0; words[i][j] != '\0'; j++) {
            mask |= 1 << (words[i][j] - 'a');
        }

        masks[i] = mask;
    }

    // Count equal masks
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {

            if (masks[i] == masks[j]) {
                count++;
            }
        }
    }

    return count;
}