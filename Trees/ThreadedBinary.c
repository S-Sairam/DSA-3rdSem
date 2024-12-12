#include <stdio.h>
#include <stdlib.h>

// Node structure for Threaded Binary Search Tree
typedef struct node {
    int data;
    struct node *left, *right;
    int leftThread;   // Flag to indicate if left pointer is a thread
    int rightThread;  // Flag to indicate if right pointer is a thread
} NODE;

// Create a new node
NODE* createNode(int key) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    newNode->leftThread = newNode->rightThread = 1;
    return newNode;
}

// Recursive insertion
NODE* insertRecursive(NODE* root, int key) {
    // If tree is empty, create root
    if (root == NULL)
        return createNode(key);
    
    // Insert into left subtree
    if (key < root->data) {
        if (root->leftThread)
            // Create new left child
            root->left = createNode(key);
        else
            // Recursively insert in left subtree
            root->left = insertRecursive(root->left, key);
        
        // Update threading
        root->leftThread = 0;
    }
    // Insert into right subtree
    else {
        if (root->rightThread)
            // Create new right child
            root->right = createNode(key);
        else
            // Recursively insert in right subtree
            root->right = insertRecursive(root->right, key);
        
        // Update threading
        root->rightThread = 0;
    }
    
    return root;
}

// Recursive inorder traversal
void inorderTraversalRecursive(NODE* root) {
    if (root == NULL)
        return;
    
    // Traverse left subtree if not a thread
    if (!root->leftThread)
        inorderTraversalRecursive(root->left);
    
    // Print current node
    printf("%d ", root->data);
    
    // Traverse right subtree if not a thread
    if (!root->rightThread)
        inorderTraversalRecursive(root->right);
}

// Find predecessor (optional but useful)
NODE* findPredecessor(NODE* node) {
    // If left thread exists, it points to predecessor
    if (node->leftThread)
        return node->left;
    
    // Otherwise, find rightmost node in left subtree
    node = node->left;
    while (!node->rightThread)
        node = node->right;
    
    return node;
}

// Find successor (optional but useful)
NODE* findSuccessor(NODE* node) {
    // If right thread exists, it points to successor
    if (node->rightThread)
        return node->right;
    
    // Otherwise, find leftmost node in right subtree
    node = node->right;
    while (!node->leftThread)
        node = node->left;
    
    return node;
}

// Main function for demonstration
int main() {
    NODE* root = NULL;
    
    // Insert some values
    root = insertRecursive(root, 50);
    root = insertRecursive(root, 30);
    root = insertRecursive(root, 70);
    root = insertRecursive(root, 20);
    root = insertRecursive(root, 40);
    root = insertRecursive(root, 60);
    root = insertRecursive(root, 80);
    
    // Perform recursive inorder traversal
    printf("Recursive Inorder Traversal: ");
    inorderTraversalRecursive(root);
    printf("\n");
    
    return 0;
}
