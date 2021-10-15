#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    int b;
    int ans;

    while (1)
    {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
        {
            break;
        }

        ans = (int)sqrt(b) - (int)sqrt(a) + ((int)sqrt(a) == sqrt(a) ? 1 : 0);
        printf("%d\n", ans);
    }

    return 0;
}