#include <stdio.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX]; // Stack array
int top = -1;    // Stack top index

// Function to push an element onto the stack
void push(char ch) {
    if (top < MAX - 1) {
        top++;
        stack[top] = ch;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; // Return null character if stack is empty
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to check if the parentheses are valid
bool isValid(const char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        char it = s[i];
        
        if (it == '(' || it == '{' || it == '[') {
            push(it);
        } else {
            if (isEmpty()) return false;
            char ch = pop();
            if ((it == ')' && ch != '(') || 
                (it == ']' && ch != '[') || 
                (it == '}' && ch != '{')) {
                return false;
            }
        }
    }
    return isEmpty();
}

int main() {
    const char* s = "()[{}()]";
    if (isValid(s))
        printf("True\n");
    else
        printf("False\n");
    
    return 0;
}
