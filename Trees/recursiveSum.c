int findSum(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + findSum(root->left) + findSum(root->right);
}
