#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
struct Node* deleteNode(struct Node* head, int data) {
    struct Node* current = head;
    struct Node* prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    } else {
        printf("Node with data %d not found\n", data);
    }

    return head;
}

void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    printf("Linked List after insertion at the beginning:\n");
    display(head);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    printf("Linked List after insertion at the end:\n");
    display(head);
    head = deleteNode(head, 3);

    printf("Linked List after deleting node with data 3:\n");
    display(head);
    freeList(head);

    return 0;
}
