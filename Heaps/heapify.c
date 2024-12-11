void heapify(int arr[], int n, int i) {
    int largest = i;         // Initialize the largest as root
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // If the left child exists and is greater than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child exists and is greater than the current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and heapify the affected subtree
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// FUCK THIS FUNCTION ALL MY HOMIES HATE IT
