int gcd(int a, int b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }
  if (a == b) {
    return a;
  }
  if (a > b) {
    return gcd(a % b, b);
  }
  else {
    return gcd(a, b % a);
  }
}
#include <stdio.h>
int main() {
  int num1, num2 ;
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
  return 0;
}