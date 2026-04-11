/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/

#include <stdio.h>

#define MAX 100
#define INF 1000000000

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    struct Edge edges[MAX];
    int dist[MAX];
    int i, j;
    int source;

    // Input vertices and edges
    scanf("%d", &n);
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u,
                          &edges[i].v,
                          &edges[i].w);
    }

    scanf("%d", &source);

    // Initialize distances
    for (i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[source] = 0;

    // Relax edges n-1 times
    for (i = 1; i <= n - 1; i++) {
        for (j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check negative cycle
    for (j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF &&
            dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    // Print shortest distances
    for (i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}