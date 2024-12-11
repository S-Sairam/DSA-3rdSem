void bfs(int adj[1000][1000], int n, int startNode) {
    int marked[1000] = {0}; // To mark visited nodes
    int queue[1000];        // Queue for BFS traversal
    int front = 0, rear = -1; // Pointers for the queue

    // Enqueue the starting node
    queue[++rear] = startNode;
    marked[startNode] = 1; // Mark the starting node as visited

    while (front <= rear) {
        // Dequeue a node from the front
        int current = queue[front++];

        // Print the current node
        printf("%d ", current);

        // Enqueue all unvisited adjacent nodes
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !marked[i]) {
                queue[++rear] = i;
                marked[i] = 1; // Mark the node as visited when enqueued
            }
        }
    }
}
