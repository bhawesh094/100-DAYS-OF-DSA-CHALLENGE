/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix (acts like adjacency list input)
int visited[MAX];    // visited array
int n;               // number of vertices

// DFS function using recursion
void dfs(int v)
{
    int i;

    // Mark current vertex as visited
    visited[v] = 1;

    // Print the vertex
    printf("%d ", v);

    // Visit all adjacent vertices
    for(i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);   // Recursive call
        }
    }
}

int main()
{
    int i, j, start;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency list (as matrix form)
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    // Input starting vertex
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // Perform DFS
    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}