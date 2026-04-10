/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>

#define MAX 100
#define INF 9999

int n;
int cost[MAX][MAX];
int dist[MAX];
int visited[MAX];

/* Function to find vertex with minimum distance */
int findMin() {
    int min = INF;
    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            pos = i;
        }
    }
    return pos;
}

/* Dijkstra Algorithm */
void dijkstra(int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMin();

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] &&
                cost[u][v] != INF &&
                dist[u] + cost[u][v] < dist[v]) {

                dist[v] = dist[u] + cost[u][v];
            }
        }
    }
}

/* Main Function */
int main() {
    int source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    printf("Shortest distances from source:\n");
    for (int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}