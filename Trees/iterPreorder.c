void iterativePreorder(NODE* root) {
    if (root == NULL) return;
    NODE* stack[100];
    int top = 0;
    stack[top++] = root;

    while (top > 0) {
        NODE* cur = stack[--top];
        printf("%d ", cur->data);

        // Push right first so that left is processed first
        if (cur->right != NULL) {
            stack[top++] = cur->right;
        }
        if (cur->left != NULL) {
            stack[top++] = cur->left;
        }
    }
}
