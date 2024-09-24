#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 3

// User-defined data type representing a student
struct student {
    int roll;      // Student roll number
    char sex;      // Student sex (m/f)
};

// Queue structure
struct queue {
    struct student list[SIZE];   // Array to store queue elements
    int front, rear;             // Indices for front and rear of the queue
    int count;                   // Number of elements in the queue
};

// Function signatures
int enqueue(struct queue *, struct student *);
int dequeue(struct queue *, struct student *);
int queue_front(struct queue *, struct student *);
int queue_rear(struct queue *, struct student *);
void reverse_queue(struct queue *);
int is_empty(struct queue *);
int search_by_roll(struct queue *, int);

void main() {
    int choice, status, roll;    // Menu choice, status of operations, and roll number
    struct queue q1;             // Queue structure
    struct student stud;         // Student structure

    // Initializing queue
    q1.front = -1; // Front of the queue is empty
    q1.rear = -1;  // Rear of the queue is empty
    q1.count = 0;  // Initial count of elements is zero

    // Menu loop
    while(1) {  // Infinite loop for menu
        clrscr();
        printf("\n ****** MENU QUEUE USING ARRAY ********");
        printf("\n 1. ENQUEUE");
        printf("\n 2. DEQUEUE");
        printf("\n 3. QUEUE_FRONT");
        printf("\n 4. QUEUE_REAR");
        printf("\n 5. REVERSAL OF QUEUE ELEMENTS");
        printf("\n 6. CHECK IF EMPTY QUEUE");
        printf("\n 7. COUNT OF QUEUE DATA NODES.");
        printf("\n 8. SEARCH THE DATA NODE IN QUEUE USING ROLL NUMBER");
        printf("\n 9. EXIT");
        printf("\n\n Enter the menu choice (1-9)- ");
        scanf("%d", &choice);    // Input user choice

        // Switch case for menu options
        switch(choice) {
            case 1: // Enqueue
                printf("\n Enter the information of new record to be inserted.");
                printf("\n\n Enter the Roll number- ");
                scanf("%d", &stud.roll);   // Input roll number
                printf("\n Enter the Sex (m / f)- ");
                flushall();                // Clear the input buffer
                scanf("%c", &stud.sex);    // Input sex
                status = enqueue(&q1, &stud);
                printf(status == 1 ? "\n Enqueue operation is successful." : "\n Enqueue operation is not successful.");
                getch();
                break;

            case 2: // Dequeue
                status = dequeue(&q1, &stud);
                if(status == 1) {
                    printf("\n DEQUEUE operation is successful.");
                    printf("\n Deleted data node having roll - %d, sex - %c", stud.roll, stud.sex);
                } else {
                    printf("\n DEQUEUE operation is not successful.");
                }
                getch();
                break;

            case 3: // Queue_front
                status = queue_front(&q1, &stud);
                if(status == 1) {
                    printf("\n Queue_Front operation is successful.");
                    printf("\n Front data node having roll - %d, sex - %c", stud.roll, stud.sex);
                } else {
                    printf("\n Queue_Front operation is not successful.");
                }
                getch();
                break;

            case 4: // Queue_Rear
                status = queue_rear(&q1, &stud);
                if(status == 1) {
                    printf("\n Queue_Rear operation is successful.");
                    printf("\n Rear data node having roll - %d, sex - %c", stud.roll, stud.sex);
                } else {
                    printf("\n Queue_Rear operation is not successful.");
                }
                getch();
                break;

            case 5: // Reversal of queue
                reverse_queue(&q1);
                printf("\n Queue elements reversed successfully.");
                getch();
                break;

            case 6: // Check if empty queue
                if (is_empty(&q1)) {
                    printf("\n The queue is empty.");
                } else {
                    printf("\n The queue is not empty.");
                }
                getch();
                break;

            case 7: // Count of queue nodes
                printf("\n Total number of data nodes in queue - %d", q1.count);
                getch();
                break;

            case 8: // Search by roll number
                printf("\n Enter the Roll number to search: ");
                scanf("%d", &roll);
                if (search_by_roll(&q1, roll)) {
                    printf("\n Roll number %d found in the queue.", roll);
                } else {
                    printf("\n Roll number %d not found in the queue.", roll);
                }
                getch();
                break;

            case 9: // Exit
                printf("\n Terminating the Menu");
                getch();
                exit(0);
                break;

            default: // Invalid input
                printf("\n Invalid choice entered!!! Retry (1-9)");
                getch();
        }
    }
}

// Enqueue operation
int enqueue(struct queue *pq1, struct student *stud) {
    if(((pq1->rear + 1) % SIZE) == pq1->front) {
        printf("\n Overflow!!!");
        getch();
        return(0);
    }
    pq1->rear = (pq1->rear + 1) % SIZE;
    pq1->list[pq1->rear] = *stud;
    pq1->count++;
    if(pq1->front == -1) {
        pq1->front = 0; // If front was -1, initialize it to 0
    }
    return(1);
}

// Dequeue operation
int dequeue(struct queue *pq1, struct student *stud) {
    if(pq1->front == -1) {
        printf("\n Underflow!!!");
        getch();
        return(0);
    }
    *stud = pq1->list[pq1->front];
    pq1->front++;
    pq1->count--;
    if(pq1->front > pq1->rear) {
        pq1->front = -1;
        pq1->rear = -1;
    }
    return(1);
}

// Return the front element of the queue
int queue_front(struct queue *pq1, struct student *stud) {
    if(pq1->front == -1) {
        printf("\n Queue is empty.");
        getch();
        return(0);
    }
    *stud = pq1->list[pq1->front];
    return(1);
}

// Return the rear element of the queue
int queue_rear(struct queue *pq1, struct student *stud) {
    if(pq1->front == -1) {
        printf("\n Queue is empty.");
        getch();
        return(0);
    }
    *stud = pq1->list[pq1->rear];
    return(1);
}

// Function to reverse the queue using a while loop and swap method
void reverse_queue(struct queue *pq1) {
    if (is_empty(pq1)) return;  // If the queue is empty, return immediately

    int start = pq1->front;     // Start index at the front of the queue
    int end = pq1->rear;        // End index at the rear of the queue

    // Swap elements between front and rear until the middle is reached
    while (start < end) {
        struct student temp = pq1->list[start];     // Temporary variable to hold the front element
        pq1->list[start] = pq1->list[end];         // Move rear element to front
        pq1->list[end] = temp;                     // Move front element to rear
        start++;                                   // Move towards the middle from the front
        end--;                                     // Move towards the middle from the rear
    }
}

// Function to check if the queue is empty
int is_empty(struct queue *pq1) {
    return pq1->front == -1;
}

// Search for a student by roll number in the queue
int search_by_roll(struct queue *pq1, int roll) {
    if (is_empty(pq1)) return 0;
    for (int i = pq1->front; i <= pq1->rear; i++) {
        if (pq1->list[i].roll == roll) {
            return 1; // Roll number found
        }
    }
    return 0; // Roll number not found
}
