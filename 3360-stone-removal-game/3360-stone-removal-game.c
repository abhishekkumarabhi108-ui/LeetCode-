#include <stdbool.h>

bool canAliceWin(int n) {

    int remove = 10;
    bool alice = true;

    while (n >= remove) {
        n -= remove;
        remove--;

        alice = !alice;
    }

    // Current player cannot make a move
    return !alice;
}