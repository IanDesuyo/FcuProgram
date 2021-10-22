#include <stdio.h>

int isPowerOfTwo(int n) {
  unsigned long a = 1;
  while (a < n) {
    a <<= 1;
  }

  return a == n;
}

int main() {
  unsigned long n;

  scanf("%lu", &n);

  if (isPowerOfTwo(n)) {
    printf("true");
  } else {
    printf("false");
  }
}
