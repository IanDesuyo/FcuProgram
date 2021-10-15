#include <stdio.h>

int main()
{
    int a, b, c;
    int space;

    // loop until user input 0 0 0
    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);
        space = -1;

        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }

        // Head
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
    }

    return 0;
}