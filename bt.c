#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Pre-order traversal
void preOrder(struct Node* node) {
    if (node) {
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

// In-order traversal
void inOrder(struct Node* node) {
    if (node) {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}

// Post-order traversal
void postOrder(struct Node* node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->data);
    }
}

// Main function
int main() {
    struct Node* root = createNode(1); // Root node
    root->left = createNode(2);        // Left child
    root->right = createNode(3);       // Right child
    root->left->left = createNode(4);  // Left-left child
    root->left->right = createNode(5); // Left-right child

    printf("Pre-order: ");
    preOrder(root);
    printf("\n");

    printf("In-order: ");
    inOrder(root);
    printf("\n");

    printf("Post-order: ");
    postOrder(root);
    printf("\n");

    return 0;
}
