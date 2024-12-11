//for array implimentation pass i starting with 0 and recursively call i as index 2r+1 for left and 2r+2 for right

int height(struct Node* root) {   // height is also same as maximum depth
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


int depth(struct Node* root, int key) { // depth of a node always requires a key
    if (root == NULL) return -1;
    if (root->data == key) return 0;
    
    int leftDepth = depth(root->left, key);
    if (leftDepth != -1) return leftDepth + 1;
    
    int rightDepth = depth(root->right, key);
    if (rightDepth != -1) return rightDepth + 1;
    
    return -1; // Node not found
}
