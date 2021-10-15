#include <stdio.h>

int main()
{
    unsigned long n;
    unsigned long m;
    unsigned long count;
    unsigned long i;

    while (scanf("%lu %lu", &n, &m) != EOF)
    {
        count = 0;
        i = 1;

        while (count < n)
        {
            count += i;
            i += m;
        }

        if (count == n)
        {
            printf("Go Kevin!!\n");
        }
        else
        {
            printf("No Stop!!\n");
        }
    }

    return 0;
}