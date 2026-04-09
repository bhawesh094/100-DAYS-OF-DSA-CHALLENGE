/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];

int main()
{
    int n, i, j;
    int front = 0, rear = -1;

    // Input number of vertices
    scanf("%d", &n);

    // Input adjacency matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize indegree
    for (i = 0; i < n; i++)
        indegree[i] = 0;

    // Calculate indegree
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Enqueue vertices with indegree 0
    for (i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            rear++;
            queue[rear] = i;
        }
    }

    // Topological Sort
    while (front <= rear)
    {
        int u = queue[front];
        front++;

        printf("%d ", u);

        for (j = 0; j < n; j++)
        {
            if (adj[u][j] == 1)
            {
                indegree[j]--;

                if (indegree[j] == 0)
                {
                    rear++;
                    queue[rear] = j;
                }
            }
        }
    }

    return 0;
}