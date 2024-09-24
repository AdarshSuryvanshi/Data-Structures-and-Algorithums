# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# define SIZE 3

// User-defined data type
// Structure definition data node
struct student {
    int roll;
    char sex;
};

struct queue {
    struct student list[SIZE];
    int front, rear;
    int count;
};

// Function signature interface
int enqueue(struct queue *, struct student *);
int dequeue(struct queue *, struct student *);
int queue_front(struct queue *, struct student *);
int queue_rear(struct queue *, struct student *);
void reverse_queue(struct queue *);
int is_queue_empty(struct queue *);
int search_queue(struct queue *, int);

void main() {
    int choice, status;
    struct queue q1;
    struct student stud;  // Insertion- to hold record for insertion in queue
                          // Deletion- to store deleted record from queue

    // Initialization of queue variable members
    q1.front = -1; // Queue array is empty
    q1.rear = -1;
    q1.count = 0;

    // *** Menu
    do {
        clrscr();
        printf("\n ****** MENU QUEUE USING ARRAY ********");
        printf("\n 1. ENQUEUE");
        printf("\n 2. DEQUEUE");
        printf("\n 3. QUEUE_FRONT");
        printf("\n 4. QUEUE_REAR");
        printf("\n 5. Reversal of Queue elements");
        printf("\n 6. Empty Queue");
        printf("\n 7. Count of Queue data node.");
        printf("\n 8. Search the data node in queue using Roll number as key");
        printf("\n 9. Exit");
        printf("\n\n Enter the menu choice (1-9)- ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Enqueue
                printf("\n Enter the information of new record to be inserted.");
                printf("\n\n Enter the Roll number- ");
                scanf("%d", &stud.roll);
                printf("\n Enter the Sex (m / f)- ");
                fflush(stdin);  // Using fflush(stdin) instead of flushall() for Turbo C++
                scanf("%c", &stud.sex);

                status = enqueue(&q1, &stud);

                if(status == 1) {
                    printf("\n Enqueue operation is successful.");
                } else {
                    printf("\n Enqueue operation is not successful.");
                }

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

            case 5: // Reversal of Queue elements
                reverse_queue(&q1);
                printf("\n Reversal of queue elements is successful.");
                getch();
                break;

            case 6: // Empty Queue
                if (is_queue_empty(&q1)) {
                    printf("\n The queue is empty.");
                } else {
                    printf("\n The queue is not empty.");
                }
                getch();
                break;

            case 7: // Count of Queue nodes
                printf("\n Total number of data nodes in queue - %d", q1.count);
                getch();
                break;

            case 8: // Search
                {
                    int roll_no;
                    printf("\n Enter Roll number to search: ");
                    scanf("%d", &roll_no);
                    int index = search_queue(&q1, roll_no);
                    if (index != -1) {
                        printf("\n Data node found at index %d: Roll number - %d, Sex - %c", 
                               index, q1.list[index].roll, q1.list[index].sex);
                    } else {
                        printf("\n Data node with Roll number %d not found in the queue.", roll_no);
                    }
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
        } // end of switch

    } while(choice != 9); // end of do-while
}

// Function definitions

int enqueue(struct queue *pq1, struct student *stud) {
    pq1->rear = (pq1->rear + 1) % SIZE;

    if(pq1->count == SIZE) {
        printf("\n Overflow!!!");
        return(0);
    }

    pq1->list[pq1->rear] = *stud;

    if(pq1->front == -1) {
        pq1->front = 0;
    }

    pq1->count++;
    return(1);
}

int dequeue(struct queue *pq1, struct student *stud) {
    if(pq1->count == 0) {
        printf("\n Underflow!!!");
        return(0);
    }

    *stud = pq1->list[pq1->front];
    pq1->front = (pq1->front + 1) % SIZE;
    pq1->count--;

    if(pq1->count == 0) {
        pq1->front = -1;
        pq1->rear = -1;
    }

    return(1);
}

int queue_front(struct queue *pq1, struct student *stud) {
    if(pq1->count == 0) {
        printf("\n Queue is empty.");
        return(0);
    }

    *stud = pq1->list[pq1->front];
    return(1);
}

int queue_rear(struct queue *pq1, struct student *stud) {
    if(pq1->count == 0) {
        printf("\n Queue is empty.");
        return(0);
    }

    *stud = pq1->list[pq1->rear];
    return(1);
}

void reverse_queue(struct queue *pq1) {
    if(pq1->count <= 1) return; // No need to reverse if queue has 0 or 1 element

    struct student temp[SIZE];
    int i = 0;
    int j = pq1->count - 1;

    // Copy elements to temporary array
    while (i < pq1->count) {
        temp[i] = pq1->list[(pq1->front + i) % SIZE];
        i++;
    }

    // Copy elements back in reverse order
    i = 0;
    while (i < pq1->count) {
        pq1->list[(pq1->front + i) % SIZE] = temp[j];
        i++;
        j--;
    }
}

int is_queue_empty(struct queue *pq1) {
    return (pq1->count == 0);
}

int search_queue(struct queue *pq1, int roll_no) {
    int i = 0;
    while (i < pq1->count) {
        int index = (pq1->front + i) % SIZE;
        if (pq1->list[index].roll == roll_no) {
            return index;
        }
        i++;
    }
    return -1; // Not found
}
