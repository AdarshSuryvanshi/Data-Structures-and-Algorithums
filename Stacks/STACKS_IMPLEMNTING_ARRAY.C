#include <stdio.h>

#define SIZE 1000

int arr[SIZE];
int top = -1;

void push(int x) {
    if (top + 1 == SIZE) {
        printf("Stack overflow\n");
        return; // Check for overflow
    }
    arr[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1; // Check for underflow
    }
    return arr[top--];
}

int Top() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1; // Check if empty
    }
    return arr[top];
}

int Size() {
    return top + 1;
}

int main() {
    push(6);
    push(3);
    push(7);

    printf("Top of stack before deleting any element: %d\n", Top());
    printf("Size of stack before deleting any element: %d\n", Size());
    printf("The element deleted is: %d\n", pop());
    printf("Size of stack after deleting an element: %d\n", Size());
    printf("Top of stack after deleting an element: %d\n", Top());

    return 0;
}
