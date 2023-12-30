#include <stdio.h>
int extended_gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}
int main() {
    int a, b;
    printf("Enter two numbers (a and b): ");
    scanf("%d %d", &a, &b);
    int x, y;
    int gcd = extended_gcd(a, b, &x, &y);
    printf("Extended GCD of %d and %d is %d\n", a, b, gcd);
    printf("Coefficients x and y are: %d and %d\n", x, y);
    return 0;
}
