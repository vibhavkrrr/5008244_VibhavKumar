#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct Stack {
    int top;
    int capacity;
    int* arr;
} Stack;

// Create stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push element
void push(Stack* stack, int x) {
    stack->arr[++stack->top] = x;
}

// Pop element
int pop(Stack* stack) {
    return stack->arr[stack->top--];
}

// Peek element
int peek(Stack* stack) {
    return stack->arr[stack->top];
}

// Two stacks for queue
Stack *s1, *s2;

// Helper: shift from s1 to s2 if needed
void shiftStacks() {
    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            push(s2, pop(s1));
        }
    }
}

// Enqueue
void enqueue(int x) {
    push(s1, x);
}

// Dequeue
void dequeue() {
    shiftStacks();
    if (!isEmpty(s2)) {
        pop(s2);
    }
}

// Print front
void printFront() {
    shiftStacks();
    if (!isEmpty(s2)) {
        printf("%d\n", peek(s2));
    }
}

int main() {
    int q;
    scanf("%d", &q);

    // Create stacks with enough capacity
    s1 = createStack(100000);
    s2 = createStack(100000);

    while (q--) {
        int type, x;
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &x);
            enqueue(x);
        } else if (type == 2) {
            dequeue();
        } else if (type == 3) {
            printFront();
        }
    }

    return 0;
}
