#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char text[128] = {0};
        int m = 0;
        int n = 0;
        scanf("%s", text);

        for (int j = 0; j < 128; j++)
        {
            if (text[j] == 0)
            {
                break;
            }
            switch (text[j])
            {
            case 0:
                break;

            case '[':
                m++;
                break;
            case ']':
                m--;
                break;

            case '(':
                n++;
                break;
            case ')':
                n--;
                break;
            }
        }

        if (m == 0 && n == 0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}