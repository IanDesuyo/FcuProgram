#include <stdio.h>

int verifyStudentId(int studentId)
{
    int iv[] = {0, 6, 7, 8, 6, 7, 8}; // ignore last digit, so multiply by 0
    int temp;
    int total = 0;
    int lastDigit = studentId % 10;
    int checkCode;

    for (int i = 0; i < 7; i++)
    {
        temp = studentId % 10 * iv[i];
        total += temp % 10 + temp / 10; // 12 = 1 + 2
        studentId /= 10;
    }

    checkCode = (10 - total % 10) % 10;
    return checkCode == lastDigit;
}

int main()
{
    int studentId;

    // Get student id
    printf("請輸入學號: D");
    scanf("%d", &studentId);

    if (verifyStudentId(studentId))
    {
        printf("學生證號正確\n");
    }
    else
    {
        printf("學生證號無效\n");
    }

    return 0;
}