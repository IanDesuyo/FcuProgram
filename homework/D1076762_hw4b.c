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
    int count[2] = {0, 0};
    int odd = 0;  // 1, 3, 5
    int even = 0; // 0, 2, 4

    // D07XXXXX~D10XXXXX
    for (int i = 700000; i <= 1099999; i++)
    {
        i % 2 == 0 ? count[0]++ : count[1]++;
        if (verifyStudentId(i))
        {
            i % 2 == 0 ? even++ : odd++;
        }
    }

    printf("單數: %d\n雙數: %d\n", odd, even);
}