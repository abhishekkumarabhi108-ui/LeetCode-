#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {

    int n = strlen(s);

    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {

        char ch = s[i];

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }

        // Closing brackets
        else {

            // No opening bracket available
            if (top == -1) {
                free(stack);
                return false;
            }

            char open = stack[top--];

            // Check matching brackets
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {

                free(stack);
                return false;
            }
        }
    }

    // Stack must be empty
    bool result = (top == -1);

    free(stack);

    return result;
}