/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/

#include <stdio.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];
int visited[MAX];
int mincost = 0;

int minKey() {
    int min = 1000000;
    int index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && graph[0][i] < min) {
            min = graph[0][i];
            index = i;
        }
    }

    return index;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph with large value
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = 1000000;
        }
    }

    int u, v, w;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    // Start from node 1
    visited[1] = 1;

    for (int count = 1; count < n; count++) {
        int min = 1000000;
        int x = 0, y = 0;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        visited[y] = 1;
        mincost += min;
    }

    printf("%d", mincost);

    return 0;
}