#include <stdio.h>

int main()
{
    unsigned int n;
    unsigned int m;
    int flag;
    while (scanf("%u %u", &n, &m) != EOF)
    {
        flag = 0;
        while (n != 1 && flag == 0)
        {
            printf("%u", n);

            if (n % m != 0)
            {
                flag = 1;
                break;
            }

            n /= m;

            printf(" ");
        }
        if (flag == 0)
        {
            printf("1\n");
        }
        else
        {
            printf("\rBoring!\n");
        }
    }

    return 0;
}