#include <stdio.h>

int main()
{
    int z;

    scanf("%d", &z);

    // y in range [33, 126];
    // (x + 10) * 3 + 6 = y
    // so x in range [-1, 30]
    for (int x = -1; x <= 30; x++)
    {
        if ((x + 30) * 3 - 63 == z)
        {
            int y = (x + 10) * 3 + 6;
            printf("%d %c", x, y);
            break;
        }
    }

    return 0;
}