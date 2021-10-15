#include <stdio.h>

int main()
{
    int r;

    scanf("%d", &r);

    printf("%.2f\n", 2 * r * 3.14);
    printf("%.2f\n", r * r * 3.14);
    printf("%.2f", 3.14 * r * r * r * 4 / 3);

    return 0;
}