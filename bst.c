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

// Function to insert a node into the BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
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
    struct Node* root = NULL;

    // Inserting nodes into the BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

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
