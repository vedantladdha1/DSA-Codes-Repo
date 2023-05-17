#include <stdio.h>
#include <stdlib.h>

// A structure to represent a heap node
struct heap_node {
  int data;
  struct heap_node *left;
  struct heap_node *right;
};

// A function to create a new heap node
struct heap_node *create_heap_node(int data) {
  struct heap_node *new_node = (struct heap_node *)malloc(sizeof(struct heap_node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// A function to swap two heap nodes
void swap_heap_nodes(struct heap_node *a, struct heap_node *b) {
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}

// A function to heapify the subtree rooted at the given node
void heapify(struct heap_node *node) {
  // If the node is a leaf node, then there is nothing to do
  if (node->left == NULL && node->right == NULL) {
    return;
  }

  // Find the largest child of the given node
  struct heap_node *largest = node;
  if (node->left != NULL && node->left->data > largest->data) {
    largest = node->left;
  }
  if (node->right != NULL && node->right->data > largest->data) {
    largest = node->right;
  }

  // If the largest child is not the given node, then swap the two nodes
  if (largest != node) {
    swap_heap_nodes(node, largest);
    heapify(largest);
  }
}

// A function to build a max heap from an array
void build_max_heap(struct heap_node **heap, int size) {
  // Iterate over all non-leaf nodes of the heap
  for (int i = (size / 2) - 1; i >= 0; i--) {
    heapify(heap[i]);
  }
}

// A function to print the max heap
void print_max_heap(struct heap_node **heap, int size) {
  // Iterate over all nodes of the heap
  for (int i = 0; i < size; i++) {
    printf("%d ", heap[i]->data);
  }
  printf("\n");
}

int main() {
  // Create an array of integers
  int data[] = {10, 5, 2, 7, 3, 9, 8, 6, 1, 4};

  // Create a max heap from the array
  struct heap_node **heap = (struct heap_node **)malloc(sizeof(struct heap_node *) * sizeof(data));
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    heap[i] = create_heap_node(data[i]);
  }

  // Build the max heap
  build_max_heap(heap, sizeof(data) / sizeof(data[0]));

  // Print the max heap
  print_max_heap(heap, sizeof(data) / sizeof(data[0]));

  // Free the heap
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    free(heap[i]);
  }
  free(heap);

  return 0;
}