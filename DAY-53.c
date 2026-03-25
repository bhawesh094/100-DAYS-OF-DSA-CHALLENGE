/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/

#include <stdio.h>

#define MAX 100

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for level order traversal
struct QueueNode {
    struct Node* node;
    int hd; // horizontal distance
};

struct QueueNode queue[MAX];
int front = 0, rear = 0;

// Array to store vertical order
int vertical[200][MAX];
int count[200];

// Function to create new node
struct Node* createNode(int data) {
    static struct Node nodes[MAX];
    static int index = 0;

    nodes[index].data = data;
    nodes[index].left = NULL;
    nodes[index].right = NULL;

    return &nodes[index++];
}

// Enqueue function
void enqueue(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

// Dequeue function
struct QueueNode dequeue() {
    return queue[front++];
}

// Function to build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* tempQueue[MAX];
    int f = 0, r = 0;

    tempQueue[r++] = root;

    int i = 1;

    while (i < n) {
        struct Node* current = tempQueue[f++];

        // Left child
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            tempQueue[r++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            tempQueue[r++] = current->right;
        }
        i++;
    }

    return root;
}

// Function for vertical order traversal
void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    int offset = 100;

    enqueue(root, 0);

    while (front < rear) {
        struct QueueNode temp = dequeue();

        struct Node* node = temp.node;
        int hd = temp.hd;

        // Store node value
        vertical[hd + offset][count[hd + offset]++] = node->data;

        if (node->left)
            enqueue(node->left, hd - 1);

        if (node->right)
            enqueue(node->right, hd + 1);
    }

    // Print vertical order
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", vertical[i][j]);
            }
            printf("\n");
        }
    }
}

// Main function
int main() {
    int n;

    // Input number of nodes
    scanf("%d", &n);

    int arr[MAX];

    // Input level order traversal
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}