#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key; 
    struct Node *left ; 
    struct Node *right ; 
}Node ;

int arr[100]; 
int i = 0;

Node *newNode(int key)
{
    Node *node  = (Node *)malloc(sizeof(Node)); 
    node->key = key; 
    node->left = NULL; 
    node->right = NULL;

    return node ; 
}

Node *insertNode(int key , Node *node){
    if(node == NULL)
        return newNode(key); 
    
    if(node->key > key)
        node->left = insertNode(key , node->left); 
    if(node->key < key)
        node->right = insertNode(key , node->right); 
    else
        return node ; 
    
    return node ; 
}

void inorder(Node*node){
    if(node != NULL){
        inorder(node->left); 
        arr[i] = node->key; 
        i = i+1; 
        inorder(node->right);
    }
}

int NthLargest(Node *node , int k){
    inorder(node); 
    return arr[k]; 
    //that simple 😂
}

void main(){
    int k ; 
    Node *node =  insertNode(69 ,node); 
    node = insertNode(79 , node); 
    node  = insertNode(89 , node); 
    // node = insertNode(10 , node); 
    int check = NthLargest(node, 0); 
    printf("%d is the 3rd largest " , check);

}


