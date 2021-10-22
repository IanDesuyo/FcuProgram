#include <stdio.h>

int number(int n) {
  int s = 0;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      s += i;
    }
  }

  if (s < n) {
    return -1;  // 虧數
  } else if (s > n) {
    return 1;  // 盈數
  } else {
    return 0;  // 完全數
  }
}

int main() {
  int n;

  while (scanf("%d", &n) != EOF) {
    switch (number(n)) {
      case -1:
        printf("虧數\n");
        break;
      case 0:
        printf("完全數\n");
        break;
      case 1:
        printf("盈數\n");
        break;
    }
  }

  return 0;
}