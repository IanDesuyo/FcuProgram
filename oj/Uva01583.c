#include <stdio.h>

int main()
{
    int n;
    int itemp;
    int m;
    int min;

    scanf("%d", &n);

    min = 100001;

    for (int i = 1; i <= n; i++)
    {
        itemp = i;
        m = i;
        while (itemp > 0)
        {
            m += itemp % 10;
            itemp /= 10;
        }

        if (m == n && i < min)
        {
            min = i;
        }
    }

    if (min == 100001)
    {
        min = 0;
    }
    printf("%d", min);

    return 0;
}