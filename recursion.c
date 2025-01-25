//
// Created by Diego Torres Durante on 10/21/24.
//

#include <stdbool.h>
#include <stdio.h>

bool isPrimeNumber(int n, int i) {
    if (n <= 2)
        return (n == 2) ? true : false;

    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;

    // Check for next divisor
    return isPrimeNumber(n, i + 1);
}

void primeNumberUser() {
    int n;
    printf("Input an integer number to analyze: ");
    scanf("%d", &n);

    bool result = isPrimeNumber(n, 2);
    if (result == true) {
        printf("true, %d", result);
    } else {
        printf("false, %d", result);
    }
}

// int main() {
//     primeNumberUser();
//     return 0;
// }
