#include <stdlib.h>
#include <string.h>

typedef struct {
    char leftChar;
    char rightChar;
    int prefix;
    int suffix;
    int best;
    int len;
} Node;

Node tree[400005];
char *str;

Node merge(Node a, Node b) {
    Node res;

    res.len = a.len + b.len;
    res.leftChar = a.leftChar;
    res.rightChar = b.rightChar;

    res.prefix = a.prefix;
    res.suffix = b.suffix;

    res.best = a.best > b.best ? a.best : b.best;

    if (a.rightChar == b.leftChar) {

        if (a.prefix == a.len)
            res.prefix = a.len + b.prefix;

        if (b.suffix == b.len)
            res.suffix = b.len + a.suffix;

        int middle = a.suffix + b.prefix;

        if (middle > res.best)
            res.best = middle;
    }

    return res;
}

void build(int node, int left, int right) {

    if (left == right) {
        tree[node].leftChar = str[left];
        tree[node].rightChar = str[left];

        tree[node].prefix = 1;
        tree[node].suffix = 1;
        tree[node].best = 1;
        tree[node].len = 1;

        return;
    }

    int mid = (left + right) / 2;

    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int left, int right, int index) {

    if (left == right) {
        tree[node].leftChar = str[index];
        tree[node].rightChar = str[index];

        tree[node].prefix = 1;
        tree[node].suffix = 1;
        tree[node].best = 1;

        return;
    }

    int mid = (left + right) / 2;

    if (index <= mid)
        update(node * 2, left, mid, index);
    else
        update(node * 2 + 1, mid + 1, right, index);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

int* longestRepeating(
    char* s,
    char* queryCharacters,
    int* queryIndices,
    int queryCharactersSize,
    int* returnSize
) {
    int n = strlen(s);
    int k = queryCharactersSize;

    str = s;

    build(1, 0, n - 1);

    int* answer = (int*)malloc(k * sizeof(int));

    *returnSize = k;

    for (int i = 0; i < k; i++) {

        int index = queryIndices[i];

        // Update character
        str[index] = queryCharacters[i];

        // Update segment tree
        update(1, 0, n - 1, index);

        // Longest repeating substring
        answer[i] = tree[1].best;
    }

    return answer;
}