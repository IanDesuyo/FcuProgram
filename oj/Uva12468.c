#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    int b;
    int ans;

    while (scanf("%d %d", &a, &b) != EOF && a != -1 && b != -1)
    {
        ans = abs(b - a);
        if (99 - b + a + 1 < ans)
        {
            ans = 99 - b + a + 1;
        }

        printf("%d\n", ans);
    }

    return 0;
}