#include <stdio.h>

long long power(long long a, long long b) {
    if (b == 0)
        return 1;

    return a * power(a, b - 1);
}

int main() {
    long long a, b;

    printf("Enter a and b: ");
    scanf("%lld %lld", &a, &b);

    if (b < 0) {
        printf("Power should be non-negative");
        return 0;
    }

    printf("Result: %lld\n", power(a, b));

    return 0;
}
