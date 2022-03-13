#include <stdio.h>

enum Person {
    Tom = 50,
    Sharon = 32,
    Bill = 40,
    Teresa = 10,
    John = 1,
}

main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a < b) {
        int t;
        t = a;
        a = b;
        b = t;
    }

    switch (a) {
        case Tom:
            printf("Tom > ");
            break;
        case Sharon:
            printf("Sharon > ");
            break;
        case Bill:
            printf("Bill > ");
            break;
        case Teresa:
            printf("Teresa > ");
            break;
        case John:
            printf("John > ");
            break;
        default:
            printf("Doesn't find\n");
            return 0;
    }

    switch (b) {
        case Tom:
            printf("Tom\n");
            break;
        case Sharon:
            printf("Sharon\n");
            break;
        case Bill:
            printf("Bill\n");
            break;
        case Teresa:
            printf("Teresa\n");
            break;
        case John:
            printf("John\n");
            break;
    }

    return 0;
}