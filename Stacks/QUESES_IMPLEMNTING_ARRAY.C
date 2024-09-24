#include <stdio.h> // C KA CODE 

#define SIZE 1000

int arr[SIZE];
int front = 0, rear = 0, count = 0;

int push(int x) {
    if (count == SIZE) return -1; // Queue overflow
    arr[rear % SIZE] = x;
    rear++;
    count++;
    return 0;
}

int pop() {
    if (count == 0) {
        printf("Queue is empty\n");
        return -1; // Indicate failure
    }
    int value = arr[front % SIZE];
    front++;
    count--;
    return value;
}

int top() {
    if (count == 0) return -1; // Queue is empty
    return arr[front % SIZE];
}

int size() {
    return count; // Return the actual count
}

int main() {
    push(6);
    push(3);
    push(7);

    printf("Top of Queue before deleting any element: %d\n", top());
    printf("Size of Queue before deleting any element: %d\n", size());
    printf("The element deleted is: %d\n", pop());
    printf("Size of Queue after deleting an element: %d\n", size());
    printf("Top of Queue after deleting an element: %d\n", top());

    return 0;
}
