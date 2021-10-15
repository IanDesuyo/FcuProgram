#include <stdio.h>

int fibCache[46] = {0};

long fibonacci(int n)
{
    if (fibCache[n] != 0)
    {
        return fibCache[n];
    }
    if (n > 2)
    {
        fibCache[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return fibCache[n];
        ;
    }
    else if (n > 0)
    {
        fibCache[n] = 1;
        return fibCache[n];
    }
    else
    {
        return 0;
    }
}

int main()
{
    int count;
    int temp;

    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &temp);
        printf("%ld\n", fibonacci(temp));
    }

    return 0;
}
