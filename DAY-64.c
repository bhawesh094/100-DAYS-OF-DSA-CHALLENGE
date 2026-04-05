/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/


#include <stdio.h>

#define MAX 100

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

// Function to insert into queue
void enqueue(int value) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

// Function to delete from queue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Function to check if queue is empty
int isEmpty() {
    if (front == -1 || front > rear)
        return 1;
    return 0;
}

int main() {
    int n, i, j, s;
    
    // Input number of vertices
    scanf("%d", &n);

    int adj[MAX][MAX];
    int visited[MAX];

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Input adjacency list as matrix form (0 or 1)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Input source vertex
    scanf("%d", &s);

    // Start BFS
    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        // Visit all adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}