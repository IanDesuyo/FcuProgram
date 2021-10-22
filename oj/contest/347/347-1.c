#include <stdio.h>

int gcd(int a, int b) {
  int t;
  if (a > b) {
    t = a;
    a = b;
    b = t;
  }

  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }

  return a;
}

int main() {
  int a, b;

  scanf("%d %d", &a, &b);
  printf("%d\n", gcd(a, b));

  return 0;
}