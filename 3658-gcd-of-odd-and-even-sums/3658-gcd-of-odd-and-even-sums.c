int gcdOfOddEvenSums(int n) {
    int sumOdd = 0;
    int sumEven = 0;

    // Sum of first n odd and even numbers
    for (int i = 1; i <= n; i++) {
        sumOdd += (2 * i - 1);
        sumEven += (2 * i);
    }

    // Find GCD using Euclidean Algorithm
    int a = sumOdd;
    int b = sumEven;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}