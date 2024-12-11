void rem_left(Deque* dq) {
    // Check if the deque is empty
    if (dq->front == NULL) {
        printf("Deque is empty. Cannot remove element.\n");
        return;
    }

    // Store the node to be removed
    Node* temp = dq->front;

    // If there is only one element in the deque
    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        // Update the front pointer to the next node
        dq->front = dq->front->next;
        dq->front->prev = NULL;  // Set the previous pointer of the new front node to NULL
    }

    // Free the memory of the removed node
    free(temp);
    printf("Left element removed.\n");
}
