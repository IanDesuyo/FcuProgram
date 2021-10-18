#include <stdio.h>

int main()
{
    int t;
    int a;
    int b;
    int sum;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        sum = 0;
        scanf("%d", &a);
        scanf("%d", &b);

        for (int j = a; j <= b; j++)
        {
            if (j % 2 == 1)
            {
                sum += j;
            }
        }
        printf("Case %d: %d\n", i + 1, sum);
    }

    return 0;
}