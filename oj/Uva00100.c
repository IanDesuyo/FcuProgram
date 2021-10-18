#include <stdio.h>
#include <math.h>

int algorithm(int n)
{
    int count = 1;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = n * 3 + 1;
        }
        count++;
    }

    return count;
}

int main()
{
    int i;
    int j;
    int t;
    int max;

    while (scanf("%d %d", &i, &j) != EOF)
    {
        printf("%d %d", i, j);
        max = 0;
        if (i > j)
        {
            t = i;
            i = j;
            j = t;
        }
        for (int n = i; n <= j; n++)
        {
            t = algorithm(n);
            if (t > max)
            {
                max = t;
            }
        }

        printf(" %d\n", max);
    }

    return 0;
}