bool checkRecord(char* s) {

    int absent = 0;
    int late = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] == 'A') {
            absent++;
        }

        if (s[i] == 'L') {
            late++;
        } else {
            late = 0;
        }

        // More than 1 absence
        if (absent >= 2) {
            return false;
        }

        // 3 consecutive late days
        if (late >= 3) {
            return false;
        }
    }

    return true;
}