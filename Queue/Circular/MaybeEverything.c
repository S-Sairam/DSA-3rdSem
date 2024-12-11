#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int front, rear, capacity;
    int *array;
} Queue;

// Function to check if the queue is full
int IsFull(Queue *PQ) {
    return (PQ->rear + 1) % PQ->capacity == PQ->front;
}

// Function to check if the queue is empty
int IsEmpty(Queue *PQ) {
    return PQ->front == -1;
}

// Function to insert an element into the queue
int Insert(Queue *PQ, int ele) {
    if (IsFull(PQ)) {
        printf("Queue is full! Cannot insert element %d\n", ele);
        return 0; // Insertion failed
    }

    // If queue is empty, initialize front to 0
    if (IsEmpty(PQ)) {
        PQ->front = 0;
    }

    // Insert the element and move rear to next position (circularly)
    PQ->rear = (PQ->rear + 1) % PQ->capacity;
    PQ->array[PQ->rear] = ele;

    return 1; // Insertion successful
}

// Function to delete an element from the queue
int Delete(Queue *PQ) {
    if (IsEmpty(PQ)) {
        printf("Queue is empty! Cannot delete element.\n");
        return -1; // Deletion failed
    }

    int deletedElement = PQ->array[PQ->front];

    // If there's only one element, reset the queue
    if (PQ->front == PQ->rear) {
        PQ->front = PQ->rear = -1;
    } else {
        // Move front to the next position (circularly)
        PQ->front = (PQ->front + 1) % PQ->capacity;
    }

    return deletedElement; // Return the deleted element
}

// Function to initialize a queue
Queue* createQueue(int capacity) {
    Queue *PQ = (Queue *)malloc(sizeof(Queue));
    PQ->capacity = capacity;
    PQ->front = PQ->rear = -1;
    PQ->array = (int *)malloc(capacity * sizeof(int));
    return PQ;
}

// Function to free the queue's memory
void freeQueue(Queue *PQ) {
    free(PQ->array);
    free(PQ);
}

int main() {
    // Create a queue of capacity 5
    Queue *PQ = createQueue(5);

    // Insert elements into the queue
    Insert(PQ, 10);
    Insert(PQ, 20);
    Insert(PQ, 30);

    // Delete elements from the queue
    printf("Deleted element: %d\n", Delete(PQ)); // Should delete 10
    printf("Deleted element: %d\n", Delete(PQ)); // Should delete 20

    // Insert more elements
    Insert(PQ, 40);
    Insert(PQ, 50);

    // Delete more elements
    printf("Deleted element: %d\n", Delete(PQ)); // Should delete 30
    printf("Deleted element: %d\n", Delete(PQ)); // Should delete 40

    // Clean up
    freeQueue(PQ);
    
    return 0;
}
