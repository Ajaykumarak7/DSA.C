#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node **dstart, int data) {
    struct Node *newNode = createNode(data);
    if (*dstart == NULL) {
        *dstart = newNode;
    } else {
        newNode->next = *dstart;
        (*dstart)->prev = newNode;
        *dstart = newNode;
    }
}
void deleteAtBeginning(struct Node **dstart) {
    if (*dstart == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node *temp = *dstart;
    *dstart = (*dstart)->next;
    if (*dstart != NULL) {
        (*dstart)->prev = NULL;
    }
    free(temp);
    printf("Deleted node at the beginning.\n");
}
void displayList(struct Node *dstart) {
    printf("Doubly linked list: ");
    while (dstart != NULL) {
        printf("%d <-> ", dstart->data);
        dstart = dstart->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node *dstart = NULL;
    insertAtBeginning(&dstart, 500);
    insertAtBeginning(&dstart, 400);
    insertAtBeginning(&dstart, 300);
    insertAtBeginning(&dstart, 200);
    insertAtBeginning(&dstart, 100);
    displayList(dstart);
    deleteAtBeginning(&dstart);
    displayList(dstart);

    return 0;
}
