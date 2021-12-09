#include <stdio.h>
#include <stdlib.h>

typedef struct person {
    char name[20];
    int year;
    int month;
    int day;
} Person;

int compare(const void* a, const void* b) {
    Person pa = *(Person*)a;
    Person pb = *(Person*)b;

    if (pa.year == pb.year) {
        if (pa.month == pb.month) {
            if (pa.day == pb.day) {
                int i = 0;
                while (1) {
                    if (pa.name[i] != pb.name[i]) {
                        return pa.name[i] - pb.name[i];
                    }
                    i++;
                }
            } else {
                return pa.day - pb.day;
            }
        } else {
            return pa.month - pb.month;
        }
    } else {
        return pa.year - pb.year;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Person people[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &people[i].year, &people[i].month, &people[i].day);
        scanf("\n%s", &people[i].name);
    }

    qsort(people, n, sizeof(Person), compare);

    for (int i = 0; i < n; i++) {
        printf("%d %d %d  %s\n", people[i].year, people[i].month, people[i].day, people[i].name);
    }

    return 0;
}