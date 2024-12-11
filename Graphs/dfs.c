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


int dfs(int a[MAX][MAX], int n, int visited[], int source, int destination) {
    // Mark the source node as visited
    visited[source] = 1;
    
    // If source is the destination, path found
    if (source == destination) 
        return 1;
    
    // Explore all adjacent nodes
    for (int i = 0; i < n; i++) {
        // Check if there's an edge and the node is not already visited
        if (a[source][i] == 1 && !visited[i]) {
            // Recursively explore this path
            if (dfs(a, n, visited, i, destination)) 
                return 1;
        }
    }
    
    // No path found
    return 0;
}
