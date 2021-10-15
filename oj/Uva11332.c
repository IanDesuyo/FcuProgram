#include <stdio.h>

int main()
{
    int total;
    long n;

    while (1)
    {
        scanf("%ld", &n);
        if (n == 0)
        {
            break;
        }
        total = n;

        while (total > 10)
        {
            total = 0;
            while (n != 0)
            {
                total += n % 10;
                n /= 10;
            }

            n = total;
        }

        printf("%d\n", total);
    }

    return 0;
}