#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a circular linked list of n people
Node* createCircularList(int n) {
    if (n <= 0) return NULL;

    Node* head = createNode(1);
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }

    // Connect the last node to the first node to make it circular
    current->next = head;
    return head;
}

// Function to find the survivor in the Josephus Problem
int findSurvivor(int n, int k) {
    // Create circular list of n people
    Node* head = createCircularList(n);

    // Pointer to track the node to be deleted
    Node* current = head;
    Node* prev = NULL;

    // Continue until only one node remains
    while (current->next != current) {
        // Find the k-th node to be eliminated
        for (int count = 1; count < k; count++) {
            prev = current;
            current = current->next;
        }

        // Remove the k-th node
        prev->next = current->next;
        
        // Free the eliminated node
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    // Return the survivor's number
    int survivor = current->data;
    free(current);
    return survivor;
}

int main() {
    int n, k;
    
    printf("Enter total number of people: ");
    scanf("%d", &n);
    
    printf("Enter elimination step (k): ");
    scanf("%d", &k);

    if (n < 1 || k < 1) {
        printf("Invalid input! Both n and k must be positive.\n");
        return 1;
    }

    int survivor = findSurvivor(n, k);
    printf("The person who survives is number %d\n", survivor);

    return 0;
}
