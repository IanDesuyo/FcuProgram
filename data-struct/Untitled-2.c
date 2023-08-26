#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100    // maximum number of planets
#define MAX_M 10000  // maximum number of routes

// graph representation
typedef struct {
    int n;                  // number of planets
    int m;                  // number of routes
    int adj[MAX_N][MAX_N];  // adjacency matrix
} Graph;

// queue representation
typedef struct {
    int size;      // current number of elements
    int capacity;  // maximum number of elements
    int *data;     // array of elements
} Queue;

// create a new empty queue
Queue *queue_new() {
    Queue *q = malloc(sizeof(Queue));
    q->size = 0;
    q->capacity = 1;
    q->data = malloc(q->capacity * sizeof(int));
    return q;
}

// free memory used by the queue
void queue_free(Queue *q) {
    free(q->data);
    free(q);
}

// add an element to the end of the queue
void queue_push(Queue *q, int value) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->data = realloc(q->data, q->capacity * sizeof(int));
    }
    q->data[q->size++] = value;
}

// remove and return the element at the front of the queue
int queue_pop(Queue *q) {
    int value = q->data[0];
    for (int i = 1; i < q->size; i++) {
        q->data[i - 1] = q->data[i];
    }
    q->size--;
    return value;
}

// return true if the queue is empty, false otherwise
bool queue_empty(Queue *q) {
    return q->size == 0;
}

// simulate the spread of TABX-4869 from the given source planet
int simulate_spread(Graph *g, int source) {
    int infected = 0;    // number of infected planets
    bool visited[g->n];  // visited[i] is true if planet i has been visited
    for (int i = 0; i < g->n; i++) visited[i] = false;
    Queue *q = queue_new();
    queue_push(q, source);
    visited[source] = true;
    infected++;
    while (!queue_empty(q)) {
        int u = queue_pop(q);
        for (int v = 0; v < g->n; v++) {
            if (g->adj[u][v] > 0 && !visited[v]) {
                queue_push(q, v);
                visited[v] = true;
                infected++;
            }
        }
    }
    queue_free(q);
    return infected;
}

int main() {
    int t;  // number of test cases
    scanf("%d", &t);
    while (t--) {
        Graph g;

        // read the input for the current test case
        scanf("%d%d", &g.n, &g.m);
        for (int i = 0; i < g.n; i++) {
            for (int j = 0; j < g.n; j++) {
                g.adj[i][j] = 0;
            }
        }
        for (int i = 0; i < g.m; i++) {
            int a, b, d;
            scanf("%d%d%d", &a, &b, &d);
            a--;
            b--;  // planets are numbered from 1 to N, so we need to subtract 1
            g.adj[a][b] = d;
            g.adj[b][a] = d;  // the graph is undirected
        }

        // find the best vaccine source
        int min_infected = INT_MAX;  // minimum number of infected planets
        int best_source = -1;        // best vaccine source
        for (int i = 0; i < g.n; i++) {
            int infected = simulate_spread(&g, i);
            if (infected < min_infected) {
                min_infected = infected;
                best_source = i;
            }
        }

        // print the result
        printf("%d\n", min_infected);
    }
    return 0;
}