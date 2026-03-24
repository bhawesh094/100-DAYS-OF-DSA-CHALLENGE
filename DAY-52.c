/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/

#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create new node
struct Node* createNode(int value)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to build tree from level order
struct Node* buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    // Create root
    struct Node* root = createNode(arr[0]);

    // Queue for level order insertion
    struct Node* queue[n];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int i = 1;

    // Build tree
    while (i < n)
    {
        struct Node* current = queue[front++];

        // Left child
        if (i < n && arr[i] != -1)
        {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1)
        {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

// Function to find LCA
struct Node* findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL)
        return NULL;

    // If one of the nodes matches root
    if (root->data == n1 || root->data == n2)
        return root;

    // Search in left and right subtree
    struct Node* left =
        findLCA(root->left, n1, n2);

    struct Node* right =
        findLCA(root->right, n1, n2);

    // If both sides returned non-NULL
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-NULL child
    if (left != NULL)
        return left;
    else
        return right;
}

int main()
{
    int n;

    // Input number of nodes
    scanf("%d", &n);

    int arr[n];

    // Input level order traversal
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int a, b;

    // Input two nodes
    scanf("%d %d", &a, &b);

    // Build tree
    struct Node* root =
        buildTree(arr, n);

    // Find LCA
    struct Node* lca =
        findLCA(root, a, b);

    // Print result
    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}