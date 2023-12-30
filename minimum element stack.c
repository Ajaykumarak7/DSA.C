#include <stdio.h>
#include <stdlib.h>
#include "stacheader.h"

int main() {
    struct stack s;
    struct stack Q;
    initialize(&s);
    initialize(&Q);

    int n, x, min;
    printf("Enter the number of elements to be entered in the stack: ");
    scanf("%d", &n);
    printf("\nEnter elements in the stack:\n");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(&s, x);
    }

    if (isEmpty(&s)) {
        min = peek(&s);
    }

    while (!isEmpty(&s)) { 
        x = pop(&s);
        min = (min < x) ? min : x;
        push(&Q, x);
    }

    while (!isEmpty(&Q)) { 
        x = pop(&Q);
        push(&s, x);
    }

    printf("Min element is %d\n", min); 
    return 0;
}
