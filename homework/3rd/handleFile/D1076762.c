#include <stdio.h>
#define MAX_DATA 1000

typedef struct {
    char name[20];
    char birthday[15];
    char phone[15];
} Data;

int main() {
    int choice;
    int line;
    FILE *f;

    if ((f = fopen("./a.txt", "rw+")) == NULL) {
        printf("Could not open a.txt .\n");
        return 0;
    }

    Data data[MAX_DATA];

    while (1) {
        rewind(f);

        for (line = 0; !feof(f); line++) {
            fscanf(f, "%s", data[line].name);
            fscanf(f, "%s", data[line].birthday);
            fscanf(f, "%s", data[line].phone);
            fscanf(f, "\n");
        }

        printf("================================================================\n");
        printf("1. Friend List\n2. Add Friend\n> ");
        scanf("%d", &choice);
        printf("================================================================\n");

        if (choice == 1) {
            printf("%-3s| %-19s| %-19s| %-14s\n", "ID", "Name", "Birthday", "Phone");
            for (int i = 0; i < line; i++) {
                printf("%3d|%20s|%20s|%15s\n", i + 1, data[i].name, data[i].birthday, data[i].phone);
            }
        } else if (choice == 2) {
            Data newData;
            printf("Name: ");
            scanf("%s", newData.name);
            printf("Birthday: ");
            scanf("%s", newData.birthday);
            printf("Phone: ");
            scanf("%s", newData.phone);

            fseek(f, 0, SEEK_END);
            fprintf(f, "%s %s %s\n", newData.name, newData.birthday, newData.phone);
            data[line] = newData;
        }
    }

    return 0;
}