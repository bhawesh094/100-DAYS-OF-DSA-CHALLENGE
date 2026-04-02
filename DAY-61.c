/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/


#include <stdio.h>

int main()
{
    int n, m;
    int i, u, v;

    // Input number of vertices and edges
    scanf("%d", &n);
    scanf("%d", &m);

    // Declare adjacency matrix
    int adj[n][n];

    // Initialize matrix with 0
    for(i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        // Add edge to matrix
        adj[u][v] = 1;

        // For undirected graph, also add reverse edge
        adj[v][u] = 1;
    }

    // Print adjacency matrix
    for(i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}