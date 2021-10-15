#include <stdio.h>

int main()
{
    int t;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int a[5] = {0};
        scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);

        if (a[3] - a[2] == a[2] - a[1])
        {
            a[4] = a[3] + a[3] - a[2];
        }
        else
        {
            a[4] = a[3] * (a[2]/a[1]);
        }
        printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
    }

    return 0;
}