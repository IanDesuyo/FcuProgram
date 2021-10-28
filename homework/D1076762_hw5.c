#include <stdio.h>
#include <stdlib.h>

// Homework 1

void homework1() {
    char asciiArt[][120] = {
        "───────────────────────────────────────",
        "───▐▀▄───────▄▀▌───▄▄▄▄▄▄▄─────────────",
        "───▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀▄──────────",
        "──▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄────────",
        "──▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄──────",
        "▀█▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌─────",
        "▀▌▒▒▒▒▒▒▀▒▀▒▒▒▒▒▒▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐───▄▄",
        "▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌▄█▒█",
        "▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒█▀─",
        "▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀───",
        "▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌────",
        "─▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐─────",
        "─▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌─────",
        "──▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐──────",
        "──▐▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▌──────",
        "────▀▄▄▀▀▀▀▀▄▄▀▀▀▀▀▀▀▄▄▀▀▀▀▀▄▄▀────────",
    };
    for (int i = 0; i < 16; i++) {
        printf("%s\n", asciiArt[i]);
    }
}

// Homework 2

void soldierCheck(float bmi) {
    printf("兵役: ");
    if (bmi < 16.5) {
        printf("免役");
    } else if (bmi < 17) {
        printf("替代役");
    } else if (bmi <= 31) {
        printf("常備役");
    } else if (bmi <= 31.5) {
        printf("替代役");
    } else {
        printf("免役");
    }
    printf("\n");
}

void policeCheck(float bmi) {
    printf("警專體檢: ");
    if (bmi < 18 || bmi > 28) {
        printf("不合格");
    } else {
        printf("合格");
    }
    printf("\n");
}

void hpaSuggest(float bmi) {
    printf("國民健康署建議: ");
    if (bmi < 18.5) {
        printf("「體重過輕」，需要多運動，均衡飲食，以增加體能，維持健康！");
    } else if (bmi < 24) {
        printf("恭喜！「健康體重」，要繼續保持！");
    } else if (bmi < 27) {
        printf("「體重過重」了，要小心囉，趕快力行「健康體重管理」！");
    } else {
        printf("啊～「肥胖」，需要立刻力行「健康體重管理」囉！");
    }
    printf("\n");
}

void homework2() {
    // Declare variables
    float bmi;
    float height;
    float weight;

    // Prompt user for height and weight
    printf("請輸入你的身高(公尺): ");
    scanf("%f", &height);

    printf("請輸入你的體重(公斤): ");
    scanf("%f", &weight);

    // Calculate BMI
    bmi = weight / (height * height);

    // Print Results
    printf("你的BMI為: %.2f\n", bmi);
    soldierCheck(bmi);
    policeCheck(bmi);
    hpaSuggest(bmi);
}
// Homework 3

void homework3() {
    // Declare variables
    int studentId;
    int registerYear;
    int registerType;

    // Get student id
    printf("請輸入學號: D");
    scanf("%d", &studentId);

    // Check register year
    registerYear = studentId / 100000;
    if (registerYear < 50)  // FCU was established in 1961(ROC 50)
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
    if (registerType <= 4) {
        printf("特殊選材/繁星推薦/海外申請\n");
    } else if (registerType <= 8) {
        printf("申請入學/四技二專徵選\n");
    } else if (registerType == 9) {
        printf("考試入學\n");
    } else {
        printf("其他管道\n");
    }

    printf("預計畢業年度(民國): %d年\n", registerYear + 4);

    printf("第五周上課方式: ");
    if (studentId % 2 == 0) {
        printf("(雙號)線上上課\n");
    } else {
        printf("(單號)實體上課\n");
    }
}

// Homework 4

int verifyStudentId(int studentId) {
    int iv[] = {0, 6, 7, 8, 6, 7, 8};  // ignore last digit, so multiply by 0
    int temp;
    int total = 0;
    int lastDigit = studentId % 10;
    int checkCode;

    for (int i = 0; i < 7; i++) {
        temp = studentId % 10 * iv[i];
        total += temp % 10 + temp / 10;  // 12 = 1 + 2
        studentId /= 10;
    }

    checkCode = (10 - total % 10) % 10;
    return checkCode == lastDigit;
}

void homework4A() {
    int studentId;

    // Get student id
    printf("請輸入學號: D");
    scanf("%d", &studentId);

    if (verifyStudentId(studentId)) {
        printf("學生證號正確\n");
    } else {
        printf("學生證號無效\n");
    }
}

void homework4B() {
    int count[2] = {0, 0};
    int odd = 0;   // 1, 3, 5
    int even = 0;  // 0, 2, 4

    // D07XXXXX~D10XXXXX
    for (int i = 700000; i <= 1099999; i++) {
        i % 2 == 0 ? count[0]++ : count[1]++;
        if (verifyStudentId(i)) {
            i % 2 == 0 ? even++ : odd++;
        }
    }

    printf("單數: %d\n雙數: %d\n", odd, even);
}

// main

void printFunctionName(char *text) {
    printf("\n====================\n");
    printf("%s", text);
    printf("\n====================\n");
}

int main() {
    int n = -1;
    while (n != 0) {
        printf("1. ASCII Art for Tamagotchi\n");
        printf("2. BMI 計算器\n");
        printf("3. 學號算命術\n");
        printf("4. 逢甲學號真實性辨識\n");
        printf("0. 離開\n");
        printf("請選擇功能: ");

        scanf("%d", &n);
        switch (n) {
            case 0:
                break;
            case 1:
                printFunctionName("ASCII Art for Tamagotchi");
                homework1();
                break;

            case 2:
                printFunctionName("BMI 計算器");
                homework2();
                break;

            case 3:
                printFunctionName("學號算命術");
                homework3();
                break;

            case 4:
                printf("1. 學號辨識工具\n");
                printf("2. 學號平均人數計算\n");
                printf("請選擇功能: ");

                scanf("%d", &n);

                switch (n) {
                    case 0:
                        break;
                    case 1:
                        printFunctionName("學號辨識工具");
                        homework4A();
                        break;

                    case 2:
                        printFunctionName("學號平均人數計算");
                        homework4B();
                        break;

                    default:
                        printf("太無情了, 連數字都能輸錯\n");
                }
                break;

            default:
                printf("太無情了, 連數字都能輸錯\n");
        }

        system("PAUSE");
        printf("\n\n\n");
    }

    return 0;
}
