#include <stdio.h>

int main()
{
    int a;
    int b;
    scanf("%d %d", &a, &b);

    if (a < b)
    {
        printf("%d", b - a);
    }
    else
    {
        printf("%d", 100 - a + b);
    }
    
    return 0;
}