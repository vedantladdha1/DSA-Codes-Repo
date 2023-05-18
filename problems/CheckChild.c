#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct node {
    int key; 
    struct node *left ; 
    struct node *right; 
}Node; 

//utilty function for creating a node 
Node *createNode (int key){
    Node *node = (Node *)malloc(sizeof(node)); 
    node->key = key; 
    node->left = NULL; 
    node->right = NULL; 
}
//1. Insert 
Node* insert(Node* node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return createNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}

Node *getRightChild(Node *node  , int key){
    while(node->key != key)
    {
        if(node->key  > key)
            node = node->left; 
        if(node->key < key)
            node = node->right;
    }

    return node->right;
}

void main(){
    Node *root = NULL;
    root = insert(root , 69); 
    insert(root ,  79);
    insert(root ,  100); 
    insert(root ,  71); 
    insert(root ,  89); 
    insert(root ,  90); 

    Node *test = getRightChild(root ,89);

    printf("%d ", test->key);
}