#include <stdio.h>
#include <stdlib.h>

// Node structure for Threaded Binary Search Tree
typedef struct node {
    int data;
    struct node *left, *right;
    int leftThread;   // Flag to indicate if left pointer is a thread
    int rightThread;  // Flag to indicate if right pointer is a thread
} NODE;

// Function to find leftmost node
NODE* leftMost(NODE* node) {
    if (node == NULL)
        return NULL;
    
    while (node->leftThread == 0)
        node = node->left;
    
    return node;
}

// Inorder traversal
void inorderTraversal(NODE* root) {
    NODE* current = leftMost(root);
    
    while (current != NULL) {
        printf("%d ", current->data);
        
        // If right is a thread, move to thread
        if (current->rightThread)
            current = current->right;
        else
            // Otherwise, find leftmost of right subtree
            current = leftMost(current->right);
    }
}

// Insert into Threaded Binary Search Tree
NODE* insert(NODE* root, int key) {
    NODE* current = root;
    NODE* parent = NULL;
    
    // Find appropriate insertion point
    while (current != NULL) {
        parent = current;
        
        if (key < current->data) {
            if (current->leftThread == 0)
                current = current->left;
            else
                break;
        } else {
            if (current->rightThread == 0)
                current = current->right;
            else
                break;
        }
    }
    
    // Create new node
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = key;
    
    // Handle insertion
    if (parent == NULL) {
        root = newNode;
        newNode->left = newNode->right = NULL;
        newNode->leftThread = newNode->rightThread = 1;
    } else if (key < parent->data) {
        // Left insertion
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftThread = 0;
        parent->left = newNode;
        newNode->leftThread = newNode->rightThread = 1;
    } else {
        // Right insertion
        newNode->right = parent->right;
        newNode->left = parent;
        parent->rightThread = 0;
        parent->right = newNode;
        newNode->leftThread = newNode->rightThread = 1;
    }
    
    return root;
}

// Main function for demonstration
int main() {
    NODE* root = NULL;
    
    // Insert some values
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    
    // Perform inorder traversal
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    
    return 0;
}
