#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 5

// Define the student structure to store roll number and sex
struct student {
    int roll;  // Roll number of the student
    char sex;  // Sex of the student ('m' or 'f')
};

// Define the queue structure
struct queue {
    struct student list[SIZE];  // Array of student records
    int front;  // Index of the front element in the queue
    int rear;   // Index of the rear element in the queue
    int count;  // Number of elements currently in the queue
};

// Function declarations
int enqueue(struct queue *, struct student *);
int dequeue(struct queue *, struct student *);
int queue_front(struct queue *, struct student *);
int queue_rear(struct queue *, struct student *);

void main() {
    int choice, status;
    struct queue q1;  // Queue instance
    struct student stud;  // Holds the student data for enqueue and dequeue

    // Initialize the queue
    q1.front = -1;  // Set the front to -1 indicating an empty queue
    q1.rear = -1;   // Set the rear to -1 indicating an empty queue
    q1.count = 0;   // Initially, the queue contains no elements

    // Menu for queue operations
    do {
        clrscr();  // Clear screen (for older compilers, can be removed for modern ones)
        printf("\n ****** MENU QUEUE USING ARRAY ********");
        printf("\n 1. ENQUEUE");
        printf("\n 2. DEQUEUE");
        printf("\n 3. QUEUE_FRONT");
        printf("\n 4. QUEUE_REAR");
        printf("\n 5. Reversal of Queue elements");  // To be implemented
        printf("\n 6. Empty Queue");  // To be implemented
        printf("\n 7. Count of Queue data nodes");
        printf("\n 8. Search the data node in queue using Roll number as key");  // To be implemented
        printf("\n 9. Exit");
        printf("\n\n Enter the menu choice (1-9): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:  // Enqueue
                printf("\n Enter the information of new record to be inserted.");
                printf("\n Enter the Roll number: ");
                scanf("%d", &stud.roll);
                printf("\n Enter the Sex (m / f): ");
                flushall();
                scanf(" %c", &stud.sex);  // Add space before %c to ignore newline characters

                status = enqueue(&q1, &stud);

                if(status == 1)
                    printf("\n Enqueue operation is successful.");
                else
                    printf("\n Enqueue operation is not successful. Queue is full.");
                getch();
                break;

            case 2:  // Dequeue
                status = dequeue(&q1, &stud);

                if(status == 1) {
                    printf("\n DEQUEUE operation is successful.");
                    printf("\n Deleted data node having roll - %d, sex - %c", stud.roll, stud.sex);
                } else {
                    printf("\n DEQUEUE operation is not successful. Queue is empty.");
                }
                getch();
                break;

            case 3:  // Queue Front
                status = queue_front(&q1, &stud);

                if(status == 1) {
                    printf("\n Queue_Front operation is successful.");
                    printf("\n Front data node having roll - %d, sex - %c", stud.roll, stud.sex);
                } else {
                    printf("\n Queue_Front operation is not successful. Queue is empty.");
                }
                getch();
                break;

            case 4:  // Queue Rear
                status = queue_rear(&q1, &stud);

                if(status == 1) {
                    printf("\n Queue_Rear operation is successful.");
                    printf("\n Rear data node having roll - %d, sex - %c", stud.roll, stud.sex);
                } else {
                    printf("\n Queue_Rear operation is not successful. Queue is empty.");
                }
                getch();
                break;

            case 7:  // Count of queue nodes
                printf("\n Total number of data nodes in queue - %d", q1.count);
                getch();
                break;

            case 9:  // Exit
                printf("\n Terminating the Menu");
                getch();
                exit(0);
                break;

            default:  // Invalid choice
                printf("\n Invalid choice entered! Retry (1-9)");
                getch();
        }
    } while(choice != 9);
}

// Function to enqueue an element
int enqueue(struct queue *pq1, struct student *stud) {
    if(pq1->count == SIZE) {  // Check if the queue is full
        printf("\n Overflow! Queue is full.");
        return 0;
    }

    pq1->rear = (pq1->rear + 1) % SIZE;  // Update rear in a circular manner
    pq1->list[pq1->rear] = *stud;  // Insert the new student data

    if(pq1->front == -1)  // If the queue was empty, set front to 0
        pq1->front = 0;

    pq1->count++;  // Increase the count of elements in the queue
    return 1;
}

// Function to dequeue an element
int dequeue(struct queue *pq1, struct student *stud) {
    if(pq1->count == 0) {  // Check if the queue is empty
        printf("\n Underflow! Queue is empty.");
        return 0;
    }

    *stud = pq1->list[pq1->front];  // Copy the front element to the provided student pointer

    pq1->front = (pq1->front + 1) % SIZE;  // Update front in a circular manner
    pq1->count--;  // Decrease the count of elements in the queue

    if(pq1->count == 0)  // If the queue becomes empty, reset front and rear
        pq1->front = pq1->rear = -1;

    return 1;
}

// Function to get the front element of the queue
int queue_front(struct queue *pq1, struct student *stud) {
    if(pq1->count == 0) {  // Check if the queue is empty
        return 0;
    }

    *stud = pq1->list[pq1->front];  // Copy the front element to the provided student pointer
    return 1;
}

// Function to get the rear element of the queue
int queue_rear(struct queue *pq1, struct student *stud) {
    if(pq1->count == 0) {  // Check if the queue is empty
        return 0;
    }

    *stud = pq1->list[pq1->rear];  // Copy the rear element to the provided student pointer
    return 1;
}
