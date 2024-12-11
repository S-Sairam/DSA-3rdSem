int length(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    
    // Traverse the list and count the nodes
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

// THIS CODE WORKS FOR BOTH SINGLY AND DOUBLY LINKED LIST ;
// FOR CIRCULARLY , KEEP ONE AT HEAD AND KEEP DO A DO WHILE LOOP UNTIL NEXT == THE ONE AT HEAD 
