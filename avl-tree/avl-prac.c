#include <stdio.h>
#include<stdlib.h>

//struct definition
typedef struct Node{
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height; 
}Node;

//function interface
int height(Node *node); 
int balanceFactor (Node*node); 
Node *insertNode(int key ,Node*node); 
Node *delNode(int key ,Node*node); 
int max(int a , int b); 
Node *createNode(int key); 
Node *leftRotate(Node*node); 
Node *rightRotate(Node *node); 

//functions 
int height(Node *node){
    if(node == NULL)
        return 0 ; 
    return node->height; 
}

//balance factor ka code 
int balanceFactor(Node *node){
    if(node == NULL)
        return 0 ; 
    return height(node->left) - height(node->right) ;
}

int max(int a ,  int b){
    return a>b?a:b; 
}

Node* createNode(int key){
    Node *node = (Node *)malloc(sizeof(Node)); 
    node->key = key; 
    node->right=  NULL; 
    node->right = NULL ; 
    node->height = 1 ;
}

Node *insertNode(int key , Node *node){
    if(node == NULL)
        return createNode(key); 
    
    //insert 
    if(node->key  > key)
        node->left = insertNode(key ,node->left); 
    if(node->key < key)
        node->right = insertNode(key , node->right); 
    else{
        return node ;
    }
    
    //now adding the avl tree props
    int balance = balanceFactor(node);

    //LL case
    if(balance > 1 && node->left->key > key)
        return rightRotate(node); 

    //LR case 
    if(balance > 1 && node->left->key < key){
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    }
    //RR case
    if(balance < -1 && node->right->key < key)
        return leftRotate(node); 
    
    //RL case
    if(balance < -1 && node->right->key >key){
        node->right = rightRotate(node->right);  
        return leftRotate(node); 
    };  

    return node ;
}

Node *leftRotate(Node *x){
    Node *b  = x->right; 
    Node *t1 =  b->left; 

    //rotation ka code 
     b->left = x; 
     x->right = t1;

    //height update

    x->height = max(height(x->left) , height(x->left)) + 1; 
    b->height = max(height(b->left) , height(b->right))+1; 

    return b; 
}

Node *rightRotate(Node *x){
    Node *b  = x->left; 
    Node *t1 =  b->right; 

    //rotation ka code 
     b->right = x; 
     x->left = t1;

    //height update

    x->height = max(height(x->left) , height(x->left)) + 1; 
    b->height = max(height(b->left) , height(b->right))+1; 

    return b; 
}

//tree traversal
void preOrder(Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

//driver function
int  main(){
    int x ; 
    int y; 
    Node *root = NULL; 
    while(1){
        printf("1 . Welcome to the program 😁 \n"); 
        printf("Enter 1 for insertion \n");
        printf("Enter 2 for printing the tree : \n "); 
        scanf("%d" , &x); 

        switch(x){
            case(1):{
                while(x !=0){
                    printf("Enter the number ->  "); 
                    scanf("%d" , &y) ;
                    root = insertNode(y ,root); 
                    scanf("%d" , &x);
                    
                }
                break;
            }
            case(2):{
                if(root == NULL){
                    printf("please enter some thing first \n");
                    break ;
                }
                else{
                    printf("this is the tree till date \n "); 
                    preOrder(root);
                    printf("\n");
                    break;
                }
                 
            }
            default:{
                printf("Made with love by rudransh 😁");
                return 0; 
            }
            
        }
    }
}

