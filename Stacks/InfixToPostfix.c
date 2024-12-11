#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to determine operator precedence
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '^') {
        return 3;
    }
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int n = strlen(infix);
    char stack[n];
    int top = -1;
    int index = 0;
    
    for (int i = 0; i < n; i++) {
        char current = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(current)) {
            postfix[index++] = current;
        }
        // If the character is '(', push it to the stack
        else if (current == '(') {
            stack[++top] = current;
        }
        // If the character is ')', pop from the stack until '('
        else if (current == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[index++] = stack[top--];
            }
            top--; // Pop the '('
        }
        // If the character is an operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(current)) {
                postfix[index++] = stack[top--];
            }
            stack[++top] = current;
        }
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        postfix[index++] = stack[top--];
    }

    postfix[index] = '\0'; // Null-terminate the postfix expression
}

// Main function
int main() {
    char infix[100], postfix[100];
    
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);  // Read the infix expression

    infixToPostfix(infix, postfix);  // Convert to postfix

    printf("Postfix expression: %s\n", postfix);  // Output the postfix expression

    return 0;
}
