int isBalanced(char* expression) {
    int length = strlen(expression);
    char stack[length];
    int top = -1;

    for (int i = 0; i < length; i++) {
        if (top != -1 && expression[i] == ')') {
            top--; // Pop the stack
        } else if (top == -1 && expression[i] == ')') {
            return 0; // Unbalanced due to unmatched closing parenthesis
        } else if (expression[i] == '(') {
            stack[++top] = '('; // Push onto the stack
        }
    }

    return top == -1; // Stack should be empty if balanced
}
