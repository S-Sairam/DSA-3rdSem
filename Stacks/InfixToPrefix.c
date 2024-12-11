
// dont rever the infix expression to get the postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to perform infix to prefix conversion
void infixToPrefix(char* infix, char* prefix) {
    int n = strlen(infix);
    char stack[n];   // Stack for operators
    int top = -1;     // Stack pointer
    int index = 0;    // Index for the result (prefix expression)
    
    // Reverse the infix expression
    for (int i = 0; i < n / 2; i++) {
        char temp = infix[i];
        infix[i] = infix[n - i - 1];
        infix[n - i - 1] = temp;
    }

    // Loop through the reversed infix expression
    for (int i = 0; i < n; i++) {
        char current = infix[i];

        // If the character is an operand (letter or digit), add it to the prefix result
        if (isalnum(current)) {
            prefix[index++] = current;
        }
        // If the character is ')', push it to the stack
        else if (current == ')') {
            stack[++top] = current;
        }
        // If the character is '(', pop from the stack until we encounter ')'
        else if (current == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[index++] = stack[top--];
            }
            top--; // Pop the ')'
        }
        // If the character is an operator, pop operators with higher or equal precedence
        else {
            while (top != -1 && (stack[top] == '*' || stack[top] == '/' || stack[top] == '^') &&
                   (current == '+' || current == '-') && precedence(stack[top]) >= precedence(current)) {
                prefix[index++] = stack[top--];
            }
            stack[++top] = current;
        }
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        prefix[index++] = stack[top--];
    }

    // Reverse the prefix expression to get the correct result
    prefix[index] = '\0'; // Null-terminate the string
    for (int i = 0; i < index / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[index - i - 1];
        prefix[index - i - 1] = temp;
    }
}

// Function to return precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }
    return 0;
}
