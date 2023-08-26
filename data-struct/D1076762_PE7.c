#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_MAX 0x7fffffff

void bfs(int p, int d, int map[p][p], int dis[]) {
    int queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = 0;
    dis[0] = 0;

    int current;
    while (front < rear) {
        current = queue[front++];
        for (int i = 0; i < p; i++) {
            if (map[current][i] == 1 && dis[i] > dis[current] + 1) {
                dis[i] = dis[current] + 1;
                queue[rear++] = i;
                map[current][i] = map[i][current] = 0;
                // printf("dis[current=%d]: %d, dis[i=%d]: %d\n", current, dis[current], i, dis[i]);
            }
        }
    }
}

int main() {
    int cases;
    FILE *f = stdin; // fopen("7.txt", "r+");
    fscanf(f, "%d", &cases);

    int p, d;
    int a, b;
    for (int c = 0; c < cases; c++) {
        fscanf(f, "%d %d", &p, &d);

        int dis[p];
        int map[p][p];
        for (int i = 0; i < p; i++) {
            dis[i] = INT_MAX;
            for (int j = 0; j < p; j++) {
                map[i][j] = 0;
            }
        }

        for (int i = 0; i < d; i++) {
            fscanf(f, "%d %d", &a, &b);
            map[a][b] = map[b][a] = 1;
        }

        bfs(p, d, map, dis);

        for (int i = 1; i < p; i++) {
            printf("%d\n", dis[i]);
        }

        printf("\n");
    }

    return 0;
}