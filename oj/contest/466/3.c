#include <stdio.h>

enum Day {
    Sunday = 1,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
}

main() {
    int n;
    scanf("%d", &n);

    switch (n) {
        case Sunday:
            printf("Today is sunday\n");
            break;
        case Monday:
            printf("Today is monday\n");
            break;
        case Tuesday:
            printf("Today is tuesday\n");
            break;
        case Wednesday:
            printf("Today is wednesday\n");
            break;
        case Thursday:
            printf("Today is thursday\n");
            break;
        case Friday:
            printf("Today is friday\n");
            break;
        case Saturday:
            printf("Today is saturday\n");
            break;
        default:
            printf("Doesn't have this day\n");
            break;
    }

    return 0;
}