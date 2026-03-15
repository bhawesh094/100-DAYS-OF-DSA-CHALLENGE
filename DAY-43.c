/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* create(int val){
    if(val==-1) return NULL;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void inorder(struct node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    int n,i;
    scanf("%d",&n);

    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct node* nodes[n];

    for(i=0;i<n;i++)
        nodes[i]=create(arr[i]);

    for(i=0;i<n;i++){
        if(nodes[i]!=NULL){
            int l=2*i+1;
            int r=2*i+2;

            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }

    inorder(nodes[0]);

    return 0;
}