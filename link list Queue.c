#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}
int front(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return queue->front->data;
}
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}
void display(Queue* queue) {
    Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void clearQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}
