/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];
int n, m;

// DFS function
void dfs(int node)
{
    visited[node] = 1;

    for(int i = 1; i <= n; i++)
    {
        if(adj[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int u, v;
    int count = 0;

    // Input nodes and edges
    scanf("%d %d", &n, &m);

    // Initialize matrix
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Read edges
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // undirected graph
    }

    // Start DFS from node 1
    dfs(1);

    // Count visited nodes
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 1)
        {
            count++;
        }
    }

    // Check connectivity
    if(count == n)
        printf("CONNECTED");
    else
        printf("NOT CONNECTED");

    return 0;
}