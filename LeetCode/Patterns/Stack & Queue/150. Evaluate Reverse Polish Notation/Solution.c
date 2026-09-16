#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int evalRPN(char** tokens, int tokensSize) {
    // Dynamic stack array to hold operands
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* token = tokens[i];

        // Check if the current token is a single-character operator
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            int b = stack[top--];
            int a = stack[top--];

            switch (token[0]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break; // C integer division truncates toward zero
            }
        } else {
            // Push operand onto stack (handles negative multi-digit numbers too)
            stack[++top] = atoi(token);
        }
    }

    int result = stack[top];
    free(stack);
    return result;
}