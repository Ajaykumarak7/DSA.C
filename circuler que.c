#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef struct {
    int front, rear;
    int data[MAX_QUEUE_SIZE];
} CircularQueue;
CircularQueue* createQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
int isEmpty(CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}
int isFull(CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front);
}
void enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }

    queue->data[queue->rear] = item;
    printf("Enqueued: %d\n", item);
}
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    }

    int item = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }

    return item;
}
void displayQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = queue->front;
    while (1) {
        printf("%d ", queue->data[i]);
        if (i == queue->rear)
            break;
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    displayQueue(queue);

    int item = dequeue(queue);
    if (item != -1) {
        printf("Dequeued: %d\n", item);
    }

    displayQueue(queue);

    return 0;
}
