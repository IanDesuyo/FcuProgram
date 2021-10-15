#include <stdio.h>
#include <string.h>

int main()
{
    int count;
    char temp[100];
    int alpha[26] = {};

    scanf("%d\n", &count);
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        fgets(temp, 100, stdin);
        printf("%d", strlen(temp));
        for (int j = 0; j < strlen(temp); j++)
        {
            if (temp[j] >= 'a' && temp[j] <= 'z')
            {
                alpha[temp[j] - 97]++;
            }
            else if (temp[j] >= 'A' && temp[j] <= 'Z')
            {
                alpha[temp[j] - 65]++;
            }
        }
    }

    int max = -1;
    int idx;
    while (max > 0)
    {
        max = 0;

        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] > max)
            {
                max = alpha[i];
                idx = i;
            }
        }

        printf("%c %d", idx + 65, alpha[idx]);
        alpha[idx] = 0;
    }

    return 0;
}