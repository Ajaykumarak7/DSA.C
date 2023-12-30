#ifndef QUEUE_H
#define QUEUE_H
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct {
    Node* front; 
    Node* rear;  
} Queue;
Queue* createQueue();
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int front(Queue* queue);
int isEmpty(Queue* queue);
void display(Queue* queue);
void clearQueue(Queue* queue);

#endif
