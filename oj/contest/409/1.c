#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int id;
    int score;
} Student;

int compare(const void *a, const void *b) {
    return (*(Student *)a).id - (*(Student *)b).id;
}

int main() {
    int n;
    scanf("%d", &n);

    Student students[n];
    char temp;
    for (int i = 0; i < n; i++) {
        scanf("\n%c%d", &temp, &students[i].id);
        scanf("%d", &students[i].score);
    }

    qsort(students, n, sizeof(Student), compare);

    for (int i = 0; i < n; i++) {
        printf("D%07d %d\n", students[i].id, students[i].score);
    }

    return 0;
}