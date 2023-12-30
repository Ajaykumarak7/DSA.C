#include <stdio.h>
#include <stdlib.h>
#include "stacheader.h"
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}
void display(Stack* stack) {
    Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
