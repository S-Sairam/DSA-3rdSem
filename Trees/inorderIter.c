void iterativeInorder(NODE* root) {
    NODE* stack[100]; 
    int top = 0;     
    NODE* cur = root;
    while (cur != NULL || top > 0) {
        while (cur != NULL) {
            stack[top++] = cur; 
            cur = cur->left;
        }
        cur = stack[--top];
        printf("%d ", cur->data);
        cur = cur->right;
    }
}
