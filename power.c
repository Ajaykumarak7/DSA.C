int power(int A, int n) {
  if (n == 0) {
    return 1;
  }
  else if (n > 0) {
    return A * power(A, n-1);
  }
  else {
    return 1 / power(A, -n);
  }
}
#include <stdio.h>
int main() {
  int A, n;
  printf("Enter the base A: ");
  scanf("%d", &A);
  printf("Enter the exponent n: ");
  scanf("%d", &n);
  printf("%d raised to the power %d is %d\n", A, n, power(A, n));
  return 0;
}
