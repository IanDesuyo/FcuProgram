#include <stdio.h>

int main()
{
    int n;
    int m;
    int pasteCount;
    int x = 1;

    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
        {
            break;
        }

        m = 1;
        pasteCount = 0;

        while (m < n)
        {
            m *= 2;
            pasteCount++;
        }

        printf("Case %d: %d\n", x++, pasteCount);
    }

    return 0;
}