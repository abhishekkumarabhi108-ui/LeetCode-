#include <stdlib.h>

typedef struct {
    int row;
    int mask;
} Row;

int compare(const void* a, const void* b) {
    Row* x = (Row*)a;
    Row* y = (Row*)b;
    return x->row - y->row;
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {

    Row rows[10000];
    int count = 0;

    // Store reserved seats as a bitmask for each row
    for (int i = 0; i < reservedSeatsSize; i++) {

        int row = reservedSeats[i][0];
        int seat = reservedSeats[i][1];

        int found = -1;

        for (int j = 0; j < count; j++) {
            if (rows[j].row == row) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            rows[count].row = row;
            rows[count].mask = 0;
            found = count++;
        }

        rows[found].mask |= (1 << seat);
    }

    int answer = (n - count) * 2;

    for (int i = 0; i < count; i++) {

        int mask = rows[i].mask;

        int left  = (mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5))) == 0;
        int middle = (mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))) == 0;
        int right = (mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9))) == 0;

        if (left && right)
            answer += 2;
        else if (left || middle || right)
            answer += 1;
    }

    return answer;
}