/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/

#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Global variable to track postorder index
int postIndex;

// Function to build tree from inorder and postorder
struct Node* buildTree(int inorder[], int postorder[], int start, int end) {

    // Base condition
    if (start > end)
        return NULL;

    // Last element in postorder is root
    int rootValue = postorder[postIndex--];

    // Create root node
    struct Node* root = createNode(rootValue);

    // If only one node
    if (start == end)
        return root;

    // Find root position in inorder
    int inIndex = search(inorder, start, end, rootValue);

    // Build right subtree first
    root->right = buildTree(inorder, postorder, inIndex + 1, end);

    // Build left subtree
    root->left = buildTree(inorder, postorder, start, inIndex - 1);

    return root;
}

// Function to print preorder traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Main function
int main() {
    int n, i;

    scanf("%d", &n);

    int inorder[n], postorder[n];

    // Input inorder
    for (i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    // Input postorder
    for (i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    // Initialize postorder index
    postIndex = n - 1;

    // Build tree
    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    // Print preorder traversal
    preorder(root);

    return 0;
}