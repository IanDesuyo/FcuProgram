#include <stdio.h>

int main()
{
    unsigned long long n;
    unsigned long long m;

    while (scanf("%llu", &n) && n != 0)
    {
        m = 11;
        while (m < n)
        {
            m += 11;
        }

        if (m == n)
        {
            printf("%d is a multiple of 11.\n", n);
        }
        else
        {
            printf("%d is not a multiple of 11.\n", n);
        }
    }

    return 0;
}