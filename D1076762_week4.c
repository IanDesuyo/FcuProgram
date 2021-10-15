#include <stdio.h>

#define RED "\x1B[31m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"

int main()
{
    int a, b, c;
    int space = -1;
    scanf("%d %d %d", &a, &b, &c);

    // Head
    printf(RED);
    for (int i = 0; i < a - 1; i++, space += 2)
    {
        // start
        for (int j = a - i; j > 0; j--)
        {
            printf(".");
        }

        printf("*");
        if (i > 0) // not the first line
        {
            // middle
            for (int k = 0; k < space; k++)
            {
                printf(".");
            }
            printf("*");
        }

        // end
        for (int j = a - i; j > 0; j--)
        {
            printf(".");
        }
        printf("\n");
    }

    // last line
    printf(".");
    for (int i = 0; i < space + 2; i++)
    {
        printf("*");
    }
    printf(".\n");

    // Body
    printf(YEL);
    for (int i = 0; i < b; i++)
    {
        printf("..");
        for (int j = 0; j < space; j++)
        {
            printf("*");
        }
        printf("..\n");
    }

    // Leg
    printf(BLU);
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < a - 1; j++)
        {
            printf(".");
        }
        for (int j = 0; j < 3; j++)
        {
            printf("*");
        }
        for (int j = 0; j < a - 1; j++)
        {
            printf(".");
        }
        printf("\n");
    }

    return 0;
}