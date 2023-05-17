#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key; 
    struct Node *left ; 
    struct Node *right; 
    int height; 
}Node; 

int height(Node *node){
    if (node == NULL)
        return 0 ; 
    return node->height; 
}

int max(int a, int b)
{
	return (a > b)? a : b;
}
// function for creating a new node 
// it will help a lot 😁

Node *createNode(int key){
    Node *node  = (Node*)malloc(sizeof(Node)); 
    node->key = key; 
    node->left  = NULL; 
    node->right =  NULL; 

    node->height = 1; 
    return node ; 
}

//functions which make an avl tree an avl tree
int balanceOf(Node *node){
    if(node == NULL)
        return 0 ; 
    return height(node->left) - height(node->right); 
}

Node *leftRotate(Node *node){
    Node *t1 = node->right ; 
    Node * t2 = t1->left ;  
    //code of rotation 
    t1->left  = node ; 
    node->right = t2; 

    //update of heights 
    node->height = max(height(node->left) , height(node->right)) + 1; 
    t1->height = max(height(t1->left) , height(t1->right)) +1 ;

    return t1 ;
}

Node *rightRotate(Node *node){
    Node *t1 = node->left ; 
    Node * t2 = t1->right ;  
    //code of rotation 
    t1->right  = node ; 
    node->left = t2; 

    //update of heights 
    node->height = max(height(node->left) , height(node->right)) + 1; 
    t1->height = max(height(t1->left) , height(t1->right)) +1 ;

    return t1; 

}


//function for inserting in the tree
//lets begin 🎹🎸

Node *insert(Node *node  ,  int key){
    if(node ==NULL)
        return createNode(key) ;
    
    //something important 
    if(key < node->key)
        node->left  = insert(node->left , key); 
    else if(key > node->key)
        node->right = insert(node->right , key); 
    else 
        return node ; 

    int balance = balanceOf(node); 

    //LL case
    if(balance > 1 && key < node->left->key)
        return rightRotate(node) ;
    //RR case
    if(balance <-1 &&key>node->right->key)
        return leftRotate(node); 

    //LR case
    if(balance > 1 && key >node->left->key){
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    }
    //RL
    if(balance <-1 && key< node->right->key){
        node->right = rightRotate(node->right) ; 
        return leftRotate(node); 
    }

    return node ; 
}

Node *minValueNode(Node *node){
    Node* current = node ; 
    
    while(current&& current->left != NULL){
        current = current->left ; 
    }

    return current ; 
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

Node *delNode(int key , Node *node){
    if(node == NULL)
        return node; 
    if(key < node->key)
        node->left  = delNode(key , node->left); 
    if(key > node->key)
        node->right = delNode(key , node->right); 
    else{
        if(node->left == NULL){
            Node *temp  = node->right;
            free(node); 
            return temp;
        }
        else if (node->right == NULL){
            Node *temp = node->left ; 
            free(node);
            return temp; 
        }
         Node *temp = minValueNode(node->right); 
        node->key = temp->key;

        node->right = delNode(temp->key , node->right);
    }
    
    int balance = balanceOf(node); 

    if(balance > 1 && key < node->left->key)
        return rightRotate(node) ;
    //RR case
    if(balance <-1 &&key>node->right->key)
        return leftRotate(node); 

    //LR case
    if(balance > 1 && key >node->left->key){
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    }
    //RL
    if(balance <-1 && key< node->right->key){
        node->right = rightRotate(node->right) ; 
        return leftRotate(node); 
    }

    return node ;
}

void main(){
    Node *root = NULL;

/* Constructing tree given in the above figure */
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);

/* The constructed AVL Tree would be
			30
		/ \
		20 40
		/ \	 \
	10 25 50
*/

printf("Preorder traversal of the constructed AVL"
		" tree is \n");
preOrder(root);
}