void front_insert(struct node **p, int x) {
    // Step 1: Create a new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = x;

    // Step 2: If the list is empty, make the new node point to itself
    if (*p == NULL) {
        new_node->next = new_node;  // Points to itself
        *p = new_node;              // Head points to the new node
    } else {
        // Step 3: If the list is not empty, insert at the front
        struct node *last = *p;
        while (last->next != *p) {
            last = last->next;  // Traverse to the last node
        }
        new_node->next = *p;  // Point new node to the current head
        *p = new_node;        // Update head to point to the new node
        last->next = *p;      // Last node points to the new head
    }
}
//same for insert last
