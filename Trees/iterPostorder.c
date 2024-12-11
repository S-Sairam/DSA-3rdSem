void iterativePostorder(NODE* root) {
    if (root == NULL) return;
    NODE* stack1[100], stack2[100];
    int top1 = 0, top2 = 0;
    stack1[top1++] = root;

    while (top1 > 0) {
        NODE* cur = stack1[--top1];
        stack2[top2++] = cur;

        // Push left and right children to stack1
        if (cur->left != NULL) {
            stack1[top1++] = cur->left;
        }
        if (cur->right != NULL) {
            stack1[top1++] = cur->right;
        }
    }

    // Now print the nodes in reverse order
    while (top2 > 0) {
        NODE* cur = stack2[--top2];
        printf("%d ", cur->data);
    }
}
