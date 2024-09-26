#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct STACK {
    int *arr;
    int top;
} stack;

int isEmpty(stack* ptr);
int isFull(stack* ptr);
void push(stack* ptr, int value);
int pop(stack* ptr);

int main() {
    stack *s = (stack*)malloc(sizeof(stack));
    if (s != NULL) {
        printf("Memory allocation for stack successful....!!!\n");
    }

    s->top = -1;  // Initialize top
    s->arr = (int*)malloc(SIZE * sizeof(int));
    if (s->arr != NULL) {
        printf("Memory allocation for stack array successful....!!!\n");
    }

    // Push a value onto the stack
    push(s, 1);

    // Check if the stack is empty
    int res = isEmpty(s);
    if (res) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty.\n");
    }

    // Pop a value from the stack
    int poppedValue = pop(s);
    if (poppedValue != -1) {
        printf("Popped value: %d\n", poppedValue);
    } else {
        printf("Stack is empty, cannot pop.\n");
    }

    // Free the allocated memory
    free(s->arr);
    free(s);
    printf("Memory freed successfully....!!!\n");

    return 0;
}

int isEmpty(stack* ptr) {
    return (ptr->top == -1);
}

int isFull(stack* ptr) {
    return (ptr->top == (SIZE - 1));
}

void push(stack* ptr, int value) {
    if (!isFull(ptr)) {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    } else {
        printf("Stack is full, cannot push.\n");
    }
}

int pop(stack* ptr) {
    if (!isEmpty(ptr)) {
        return ptr->arr[ptr->top--];
    } else {
        printf("Stack is empty, cannot pop.\n");
        return -1; // Return an error value
    }
}
