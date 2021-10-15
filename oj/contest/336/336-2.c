#include <stdio.h>

int main()
{
    char a[32] = {0};
    char b[33] = {0};
    int flag = 0;

    scanf("%s", a);

    for (int i = 0; i < 32; i++)
    {
        b[i] = a[31 - i];
    }

    for (int j = 0; j < 32; j++)
    {
        if (b[j] != 0)
        {
            if (b[j] == '0' && b[j + 1] == '0')
            {
                continue;
            }
            else if (b[j] == '0' && b[j + 1] != '0' && !flag)
            {
                flag = 1;
                continue;
            }
            printf("%c", b[j]);
        }
    }

    return 0;
}