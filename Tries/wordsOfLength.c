#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 256

typedef struct trienode {
    struct trienode* letters[MAX_CHARS];
    bool terminal;
} NODE;

// Function prototypes
void printWordsOfLengthRec(NODE* node, unsigned char* buffer, int currentLength, int targetLength);
void printWordsOfLength(NODE* root, int targetLength);

// Recursive function to print words of a specific length
void printWordsOfLengthRec(NODE* node, unsigned char* buffer, int currentLength, int targetLength) {
    if (node == NULL) {
        return;
    }

    // If the word reaches the target length and is terminal, print it
    if (currentLength == targetLength && node->terminal) {
        buffer[currentLength] = '\0'; // Null-terminate the word
        printf("WORD: %s\n", buffer);
        return;
    }

    // If the current length exceeds the target length, stop the traversal
    if (currentLength >= targetLength) {
        return;
    }

    // Recurse for all possible letters
    for (int i = 0; i < MAX_CHARS; i++) {
        if (node->letters[i] != NULL) {
            buffer[currentLength] = i; // Add the character to the buffer
            printWordsOfLengthRec(node->letters[i], buffer, currentLength + 1, targetLength);
        }
    }
}

// Wrapper function to print words of a specific length
void printWordsOfLength(NODE* root, int targetLength) {
    if (root == NULL) {
        printf("TRIE IS EMPTY\n");
        return;
    }

    unsigned char buffer[targetLength + 1]; // Buffer to store the word being formed
    printWordsOfLengthRec(root, buffer, 0, targetLength);
}
