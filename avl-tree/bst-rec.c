#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

struct Node *insert(struct Node* node , int key){
    if(node == NULL)
        return(newNode(key)); 
    
    if(key < node->key)
        node->left = insert(node->left, key); 
    if(key > node->key)
        node->right = insert(node->right , key);

    return node ; 
}

struct Node *deleteNode(struct Node* node , int key){
    if(node  == NULL)
        return node ; 
    
}

void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
struct Node *root = NULL;

/* Constructing tree given in the above figure */
root = insert(root, 10);
root = insert(root, 5);
root = insert(root, 20);
root = insert(root, 15);


printf("Preorder traversal of the constructed AVL"
		" tree is \n");
preOrder(root);

return 0;
}
