void dfs(int adj[1000][1000], int n, int startNode) {
    int marked[1000] = {0}; // To mark visited nodes
    int stack[1000];        // Stack for DFS traversal
    int top = -1;           // Stack pointer

    stack[++top] = startNode;

    while (top > -1) {
        int current = stack[top--];

        if (marked[current])
            continue;

        marked[current] = 1;
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !marked[i]) {
                stack[++top] = i;
            }
        }
    }
}
