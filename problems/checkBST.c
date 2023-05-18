#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{
    int key; 
    struct Node* left; 
    struct Node *right;
}Node ; 

Node *newNode(int key)
{
    Node *node  = (Node*)malloc(sizeof(Node)); 
    node->key = key; 
    node->left= NULL; 
    node->right = NULL; 

    return node; 
} 

Node *insertNode(int key , Node *node)
{
    if(node == NULL)
        return newNode(key); 
    
    //
    if(node->key < key)
        node->right = insertNode(key , node->right); 
    if(node->key > key)
        node->left = insertNode(key , node->left); 
    else
        return node ; 
    
    return node; 
}

int maxValue(Node *node){
    if(node == NULL)
        return 0; 
    
    int leftMax = maxValue(node->left); 
    int rightMax = maxValue(node->right); 

    int value =  0; 

    if(leftMax > rightMax){
        value = leftMax; 
    }
    else {
        value = rightMax;
    }

    if (value < node->key) {
        value = node->key;
    }
    return value;
}

int minValue(Node *node){
    if(node == NULL)
        return 1000000000;
    int leftMax = minValue(node->left); 
    int rightMax = minValue(node->right); 

    int value = 0 ; 
    if(leftMax < rightMax)
        value = leftMax; 
    else
        value = rightMax; 
    
    if(value > node->key)
        value = node->key; 

    return value;
}

int checkBST(Node *node){
    if(node == NULL)
        return 1; 
    if(node->left !=NULL && maxValue(node->left) > node->key)
        return 0 ; 
    if(node->right !=NULL && maxValue(node->right) < node->key)
        return 0 ;
    if(checkBST(node->left) == 0  || checkBST(node->right) == 0)
        return 0; 

    return 1;
}

int main()
{
     Node* root = newNode(4);
    root->left = newNode(3);
    root->right = newNode(6);
   // root->left->left = newNode(1);
    //root->left->right = newNode(3);
 
    // Function call
    if (checkBST(root))
        printf("Is BST");
    else
        printf("Not a BST");
 
    getchar();
    return 0;
}

