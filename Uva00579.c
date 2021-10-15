#include <stdio.h>

int main()
{
    int h;
    int m;
    float deg;

    while (1)
    {
        scanf("%d:%d", &h, &m);
        if (h == 0 && m == 0)
        {
            break;
        }

        deg = h * 30;
        deg += m * 0.5;

        if (deg >= 180)
        {
            deg -= 180;
        }

        printf("%.3f\n", deg);
    }

    return 0;
}