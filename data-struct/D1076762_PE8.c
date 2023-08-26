#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dfs(int n, int adjList[n][n], int visited[n], int planet) {
    visited[planet] = 1;

    int count = 1;
    for (int i = 1; i <= n; i++) {
        if (adjList[planet][i] && !visited[i]) {
            count += dfs(n, adjList, visited, i);
        }
    }

    return count;
}

int main() {
    int T, N, M, A, B, D;
    scanf("%d", &T);

    for (int c = 0; c < T; c++) {
        scanf("%d %d", &N, &M);

        int adjList[N + 1][N + 1];
        int visited[N + 1];
        memset(adjList, 0, sizeof(adjList));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &A, &B, &D);
            adjList[A][B] = adjList[B][A] = D;
        }

        int maxInfected = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                int infected = dfs(N, adjList, visited, i);
                maxInfected = maxInfected > infected ? maxInfected : infected;
            }
        }

        printf("%d\n", maxInfected - 1);
    }
    return 0;
}