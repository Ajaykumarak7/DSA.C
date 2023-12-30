#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 1000
#define TRUE 1
#define FALSE 0

struct stack {
    char item[STACKSIZE];
    int top;
};

void initialize(struct stack *S) {
    S->top = -1;
}
int isEmpty(struct stack *S) {
    return (S->top == -1) ? TRUE : FALSE;
}

void push(struct stack *S, char k) {
    if (S->top == STACKSIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    } else {
        S->top++;
        S->item[S->top] = k;
    }
}

char pop(struct stack *S) {
    if (isEmpty(S)) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        char x = S->item[S->top];
        S->top--;
        return x;
    }
}

char peek(struct stack *S) {
    return S->item[S->top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPost(char infixExp[]) {
    struct stack s;
    initialize(&s);
    char postfixExp[STACKSIZE];
    int i, j;
    i = j = 0;

    while (infixExp[i] != '\0') {
        char c = infixExp[i];

        if (isalnum(c)) {
            postfixExp[j] = c;
            j++;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfixExp[j] = pop(&s);
                j++;
            }
            pop(&s); // Pop '('
        } else if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                postfixExp[j] = pop(&s);
                j++;
            }
            push(&s, c);
        }

        i++;
    }

    while (!isEmpty(&s)) {
        postfixExp[j] = pop(&s);
        j++;
    }

    postfixExp[j] = '\0';
    printf("Postfix expression: %s\n", postfixExp);
}

int main() {
    char infixExp[STACKSIZE];
    printf("Enter the infix expression: ");
    scanf("%s", infixExp);
    infixToPost(infixExp);

    return 0;
}
