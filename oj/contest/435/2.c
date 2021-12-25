#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char data[1002];
    int len;
    long long int sum = 0;

    scanf("%s", data);
    len = strlen(data);

    for (int i = 0; i < len; i++) {
        sum = sum * 26 + (data[i] - 64);
    }

    printf("%lld\n", sum);

    return 0;
}