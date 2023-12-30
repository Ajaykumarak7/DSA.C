#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKS 3
#define STACK_SIZE 100

struct MultiStack {
    int top[MAX_STACKS];
    int data[MAX_STACKS][STACK_SIZE];
};

void initialize(struct MultiStack* ms) {
    for (int i = 0; i < MAX_STACKS; i++) {
        ms->top[i] = -1;
    }
}

int isFull(struct MultiStack* ms, int stackNumber) {
    return ms->top[stackNumber] == STACK_SIZE - 1;
}

int isEmpty(struct MultiStack* ms, int stackNumber) {
    return ms->top[stackNumber] == -1;
}

void push(struct MultiStack* ms, int stackNumber, int value) {
    if (!isFull(ms, stackNumber)) {
        ms->top[stackNumber]++;
        ms->data[stackNumber][ms->top[stackNumber]] = value;
    } else {
        printf("Stack %d is full. Cannot push %d\n", stackNumber, value);
    }
}

int pop(struct MultiStack* ms, int stackNumber) {
    if (!isEmpty(ms, stackNumber)) {
        int value = ms->data[stackNumber][ms->top[stackNumber]];
        ms->top[stackNumber]--;
        return value;
    } else {
        printf("Stack %d is empty. Cannot pop.\n", stackNumber);
        return -1;
    }
}

int peek(struct MultiStack* ms, int stackNumber) {
    if (!isEmpty(ms, stackNumber)) {
        return ms->data[stackNumber][ms->top[stackNumber]];
    } else {
        printf("Stack %d is empty. Cannot peek.\n", stackNumber);
        return -1;
    }
}
int main() {
    struct MultiStack ms;
    initialize(&ms); 
}
