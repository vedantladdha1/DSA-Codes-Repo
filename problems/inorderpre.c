#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key; 
    struct Node *left ; 
    struct Node *right ; 
}Node ;

int arr[100]; 
int i = 0;
int count = 0 ; 

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

int inorderpre(Node *node){
    inorder(node);
    int val = node->key; 
    int k = 0 ;

    for(i=0;i<7;i++){
        if(arr[i] == node->key){
            return arr[i-1];
            break;
        }
    }
}

int postorderpre(Node *node){
    inorder(node);
    int val = node->key; 
    int k = 0 ;

    for(i=0;i<7;i++){
        if(arr[i] == node->key){
            return arr[i+1];
            break;
        }
    }
}

void main(){
    int k ; 
    Node *root = NULL;
    root = insertNode(50, root);
    insertNode(30,root);
    insertNode(20,root);
    insertNode(40,root);
    insertNode(70,root);
    insertNode(60,root);
    insertNode(80,root);

    int ipre = inorderpre(root); 
    int opre = postorderpre(root);
    printf("%d is the inorder predecessor " ,ipre); 
    printf("%d is the postorder predecessor " ,opre); 

    
    // node = insertNode(10 , node); 
}
