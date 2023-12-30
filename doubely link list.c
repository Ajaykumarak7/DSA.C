#include<stdio.h>    
#include<stdlib.h>
struct node
 {
    int info;
    struct node *prev;
    struct node *next;
};
struct node * GetNode() {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void InsBeg(struct node **dstart, int x) {
    struct node *p;
    p = GetNode();
    p->info = x;
    p->next = (*dstart);
    if ((*dstart) != NULL)
        (*dstart)->prev = p;
    (*dstart) = p;
}
void InsEnd(struct node **dstart, int x) {
    struct node *p, *temp;
    p = GetNode();
    p->info = x;
    p->next = NULL;
    if ((*dstart) == NULL) {
        p->prev = NULL;
        (*dstart) = p;
    } else {
        temp = (*dstart);
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
}
void InsAfter(struct node *prevNode, int x) {
    if (prevNode == NULL) {
        printf("Cannot insert after. Invalid node.\n");
        return;
    }
    struct node *p = GetNode();
    p->info = x;
    p->next = prevNode->next;
    p->prev = prevNode;
    if (prevNode->next != NULL) {
        prevNode->next->prev = p;
    }
    prevNode->next = p;
}
void InsBefore(struct node **dstart, struct node *nextNode, int x) {
    if (nextNode == NULL) {
        printf("Cannot insert before. Invalid node.\n");
        return;
    }
    struct node *p = GetNode();
    p->info = x;
    p->prev = nextNode->prev;
    p->next = nextNode;
    if (nextNode->prev != NULL) {
        nextNode->prev->next = p;
    } else {
        (*dstart) = p; 
    }
    nextNode->prev = p;
}
void Traverse(struct node *dstart) {
    struct node *p;
    p = dstart;
    while (p != NULL) {
        printf("\t  %d", p->info);
        p = p->next;
    }
}
int main() {
    struct node *dstart = NULL; 
    InsBeg(&dstart, 100);
    InsBeg(&dstart, 200);
    InsBeg(&dstart, 300);
    InsBeg(&dstart, 400);
    InsBeg(&dstart, 500);
    printf("Doubly linked list after insertions:\n");
    Traverse(dstart);
    struct node *nodeAfter = dstart->next->next;
    InsAfter(nodeAfter, 350);
    struct node *nodeBefore = dstart->next->next->next;
    InsBefore(&dstart, nodeBefore, 375);
    printf("\nDoubly linked list after additional insertions:\n");
    Traverse(dstart); 
    return 0;
}
