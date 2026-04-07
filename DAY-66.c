/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>

int dfs(int node, int n, int graph[100][100], int visited[], int recStack[])
{
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1)
        {
            if (!visited[i])
            {
                if (dfs(i, n, graph, visited, recStack))
                    return 1;
            }
            else if (recStack[i])
            {
                return 1; // Cycle found
            }
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    int graph[100][100];

    // Input adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int visited[100] = {0};
    int recStack[100] = {0};

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, n, graph, visited, recStack))
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}