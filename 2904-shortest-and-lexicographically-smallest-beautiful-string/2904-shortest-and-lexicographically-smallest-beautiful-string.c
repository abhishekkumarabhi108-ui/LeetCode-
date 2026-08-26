#include <stdlib.h>
#include <string.h>

char* shortestBeautifulSubstring(char* s, int k) {

    int n = strlen(s);
    char* ans = malloc((n + 1) * sizeof(char));
    ans[0] = '\0';

    for (int i = 0; i < n; i++) {

        int count = 0;

        for (int j = i; j < n; j++) {

            if (s[j] == '1')
                count++;

            if (count == k) {

                int len = j - i + 1;

                char* sub = malloc((len + 1) * sizeof(char));

                strncpy(sub, s + i, len);
                sub[len] = '\0';

                if (ans[0] == '\0' ||
                    len < strlen(ans) ||
                    (len == strlen(ans) && strcmp(sub, ans) < 0)) {

                    strcpy(ans, sub);
                }

                free(sub);
                break;
            }
        }
    }

    return ans;
}