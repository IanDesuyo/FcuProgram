#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_direction(int *dir_i, int *dir_j) {
    switch (rand() % 8) {
        case 0:
            *dir_i = 1;
            *dir_j = 1;
            break;

        case 1:
            *dir_i = 1;
            *dir_j = 0;
            break;

        case 2:
            *dir_i = 1;
            *dir_j = -1;
            break;

        case 3:
            *dir_i = 0;
            *dir_j = -1;
            break;

        case 4:
            *dir_i = -1;
            *dir_j = -1;
            break;

        case 5:
            *dir_i = -1;
            *dir_j = 0;
            break;

        case 6:
            *dir_i = -1;
            *dir_j = 1;
            break;

        case 7:
            *dir_i = 0;
            *dir_j = 1;
            break;

        default:
            break;
    }
}

int is_done(int n, int m, int map[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!map[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    // initialize random seed
    srand(time(NULL));

    int n, m, start_i, start_j;

    scanf("%d%d%d%d", &n, &m, &start_i, &start_j);

    if (start_j < 1 || start_j >= m || m > 20 || start_i < 2 || start_i >= n || n > 40) {
        printf("錯誤訊息！\n");
        return 0;
    }

    int i, j;
    int dir_i, dir_j, count = 0;
    int map[n][m];
    int curr_i = start_i, curr_j = start_j;

    // initialize map
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            map[i][j] = 0;
        }
    }

    map[curr_i][curr_j] = 1;

    while (count < 50000) {
        rand_direction(&dir_i, &dir_j);

        // hit the wall
        if (curr_i + dir_i < 0 || curr_i + dir_i >= n || curr_j + dir_j < 0 || curr_j + dir_j >= m) {
            continue;
        }

        // move
        curr_i += dir_i;
        curr_j += dir_j;

        map[curr_i][curr_j] += 1;
        count++;

        if (is_done(n, m, map)) {
            break;
        }
    }

    // print result
    printf("The total number of moves = %d\n", count);

    int avg = count / (n * m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // make it colorful <3
            if (i == start_i && j == start_j) {
                printf("\e[34m%05d\e[0m ", map[i][j]);
            } else if (map[i][j] > avg) {
                printf("\e[31m%05d\e[0m ", map[i][j]);
            } else if (map[i][j] > avg / 2) {
                printf("\e[33m%05d\e[0m ", map[i][j]);
            } else if (map[i][j] > avg / 4) {
                printf("\e[32m%05d\e[0m ", map[i][j]);
            } else {
                printf("%05d ", map[i][j]);
            }
        }
        printf("\n");
    }

    // write to file
    FILE *fp = fopen("D1076762_PE2.csv", "w");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fprintf(fp, "%d%c", map[i][j], ",\n"[j == m - 1]);
        }
    }

    fclose(fp);

    return 0;
}