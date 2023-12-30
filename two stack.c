#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
struct TwoStacks {
    int top1;
    int top2;
    int data[MAX_SIZE];
};
void initialize(struct TwoStacks* ts) {
    ts->top1 = -1;
    ts->top2 = MAX_SIZE;
}
int isFull(struct TwoStacks* ts) {
    return ts->top1 + 1 == ts->top2;
}
int isEmpty1(struct TwoStacks* ts) {
    return ts->top1 == -1;
}
int isEmpty2(struct TwoStacks* ts) {
    return ts->top2 == MAX_SIZE;
}
void push1(struct TwoStacks* ts, int value) {
    if (!isFull(ts)) {
        ts->data[++ts->top1] = value;
    } else {
        printf("Stack 1 is full. Cannot push %d\n", value);
    }
}
void push2(struct TwoStacks* ts, int value) {
    if (!isFull(ts)) {
        ts->data[--ts->top2] = value;
    } else {
        printf("Stack 2 is full. Cannot push %d\n", value);
    }
}
int pop1(struct TwoStacks* ts) {
    if (!isEmpty1(ts)) {
        return ts->data[ts->top1--];
    } else {
        printf("Stack 1 is empty. Cannot pop.\n");
        return -1; 
    }
}
int pop2(struct TwoStacks* ts) {
    if (!isEmpty2(ts)) {
        return ts->data[ts->top2++];
    } else {
        printf("Stack 2 is empty. Cannot pop.\n");
        return -1;
    }
}
int peek1(struct TwoStacks* ts) {
    if (!isEmpty1(ts)) {
        return ts->data[ts->top1];
    } else {
        printf("Stack 1 is empty. Cannot peek.\n");
        return -1;
    }
}
int peek2(struct TwoStacks* ts) {
    if (!isEmpty2(ts)) {
        return ts->data[ts->top2];
    } else {
        printf("Stack 2 is empty. Cannot peek.\n");
        return -1; 
    }
}
int main() {
    struct TwoStacks ts;
    initialize(&ts);
    return 0;
}
