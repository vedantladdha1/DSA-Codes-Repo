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

Node* MinValNode(Node *node)
{
    Node *current = node; 
    while(current &&current->left != NULL )
    {
        current = current->left; 
    }
    return current ; 
}

Node *delNode(int key , Node *node){
    if(node == NULL)
        return node; 
    if(node->key > key)
        node->left = delNode(key , node->left); 
    if(node->key < key)
        node->right = delNode(key ,node->right) ;

    else{
        if(node->left == NULL){
            Node*temp = node->right; 
            free(node);
            return temp;
        }
        else if(node->right == NULL)
        {
            Node*temp = node->left; 
            free(node);
            return temp;
        }

        Node *temp = MinValNode(node->right); 
        node->key = temp->key; 

        node->right = delNode(temp->key , node->right);

    }
    return node;
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
    node = delNode(69 ,node);
    int check = NthLargest(node, 0); 
    printf("%d is the 3rd largest " , check);

}


