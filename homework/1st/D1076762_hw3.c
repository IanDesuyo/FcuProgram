#include <stdio.h>
#include <time.h>

int main()
{
    // Declare variables
    int studentId;
    int registerYear;
    int registerType;

    // Get student id
    printf("請輸入學號: D");
    scanf("%d", &studentId);

    // Check register year
    registerYear = studentId / 100000;
    if (registerYear < 50) // FCU was established in 1961(ROC 50)
    {
        registerYear += 100;
    }

    // Check register type
    registerType = (studentId / 10000) % 10;

    // Outputs
    printf("\n");
    printf("學號: D%07d\n", studentId);
    printf("入學年度(民國): %d年\n", registerYear);

    printf("可能的入學管道: ");
    if (registerType <= 4)
    {
        printf("特殊選材/繁星推薦/海外申請\n");
    }
    else if (registerType <= 8)
    {
        printf("申請入學/四技二專徵選\n");
    }
    else if (registerType == 9)
    {
        printf("考試入學\n");
    }
    else
    {
        printf("其他管道\n");
    }

    printf("預計畢業年度(民國): %d年\n", registerYear + 4);

    printf("第五周上課方式: ");
    if (studentId % 2 == 0)
    {
        printf("(雙號)線上上課\n");
    }
    else
    {
        printf("(單號)實體上課\n");
    }

    return 0;
}