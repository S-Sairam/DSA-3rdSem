void display_of_length(TRIE *root, char *str, int level, int length) {
    // Base case: if current node is NULL, return
    if (root == NULL)
        return;
    
    // If we've reached the desired length and this is a valid word (leaf node)
    if (level == length && root->isLeaf) {
        // Null-terminate the string at current level
        str[level] = '\0';
        // Print the word
        printf("%s\n", str);
    }
    
    // Explore all possible child nodes (26 lowercase letters)
    for (int i = 0; i < 26; i++) {
        // If child exists
        if (root->child[i] != NULL) {
            // Add current character to string
            str[level] = i + 'a';
            
            // Recursively explore this path
            display_of_length(root->child[i], str, level + 1, length);
        }
    }
}
