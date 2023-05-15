#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key ;
    struct node *left; 
    struct node *right; 
    int height; 
}Node ; 

int height(Node *n){
    if(n == NULL){
        return 0 ;     
    }
    return n->height; 
}

int max(int a ,  int b){
    return (a>b)?a:b ;
}

Node* newNode(int key){
    Node *node = (Node*)malloc(sizeof(node)); 
    node->key = key; 
    node->left = NULL; 
    node->right = NULL ; 
    node->height = 1 ; 

    return (node); 
}

Node* rightRotate(Node *y){
    Node *x = y->left; 
    Node *t2 = x->right; 

    //perform rotation
    x->right = y; 
    y->left = t2 ; 

    //update heights
    y->height = max(height(y->left) , height(y->right)) + 1; 
    x->height = max(height(x->left), height(x->right)) + 1;

    //return new root
    return x;  
}

Node *leftRotate(Node *x){
    Node * y = x->right; 
    Node *t2 = y->left; 

    //perform rotation
    y->left = x; 
    x->right = t2; 

    //update height
    x->height = max(height(x->left) , height(x->right))+1; 
    y->height = max(height(y->left) , height(y->right))+1; 

    //return root
    return y; 
}

int getBalance(Node *n){
    if(n == NULL){
        return 0; 
    }
    return height(n->left) - height(n->right); 
}

Node *insert(Node *node , int key){
    if(node == NULL)
        return (newNode(key)); 
    
    if(key < node->key)
        node->left = insert(node->left , key); 
    else if(key > node->key)
        node->right = insert(node->right , key); 
    else
        return node ;

    node->height = 1 + max(height(node->left) , height(node->right));

    int balance = getBalance(node); 

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node ; 
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void main(){
    Node *root  = NULL; 

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);

}

