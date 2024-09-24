# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

// Define the structure for a student node
struct student {
    int roll;                 // Roll number of the student
    char sex;                 // Sex of the student ('m' or 'f')
    struct student *next;     // Pointer to the next node
};

// Define the structure for the header node
struct header {
    struct student *first;    // Pointer to the first node in the list
    int count;                // Count of nodes in the list
};

// Function signatures
struct student *allocate(void);
void insert_beg(struct header *, struct student *);
void insert_end(struct header *, struct student *);
void traversal(struct header *);
void delete_beg(struct header *);
void delete_end(struct header *);
void delete_position(struct header *, int);
void insert_after(struct header *, struct student *, int);
void searching(struct header *, int);

void main() {
    int choice, position, number;
    struct student *temp;
    struct header h1;

    h1.first = NULL;  // Initialize header
    h1.count = 0;

    do {
        clrscr();  // Clear screen (Turbo C++ specific function)

        // Menu for user interaction
        printf("\n ******** Menu options for Single Linked List **********\n");
        printf("\n 01. Insert at the beginning of the list.");
        printf("\n 02. Insert at the end of the list.");
        printf("\n 03. Insert after an existing node.");
        printf("\n 04. Delete the first node.");
        printf("\n 05. Delete the last node.");
        printf("\n 06. Delete a node at a specific position.");
        printf("\n 07. Traverse the list.");
        printf("\n 08. Search by roll number.");
        printf("\n 09. Display the count of nodes.");
        printf("\n 10. Exit\n");
        printf("\n Enter your choice (01-10) - ");
        flushall();  // Clear input buffer (Turbo C++ specific function)
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Insert at the beginning
                temp = allocate();
                if(temp == NULL) {
                    printf("\n Overflow!!! Insufficient memory.");
                    getch();
                    break;
                }
                insert_beg(&h1, temp);
                break;

            case 2:
                // Insert at the end
                temp = allocate();
                if(temp == NULL) {
                    printf("\n Overflow!!! Insufficient memory.");
                    getch();
                    break;
                }
                insert_end(&h1, temp);
                break;

            case 3:
                // Insert after an existing node
                if(h1.first != NULL) {
                    do {
                        printf("\n Enter the position (1-%d): ", h1.count);
                        scanf("%d", &position);
                    } while(position <= 0 || position > h1.count);
                } else {
                    printf("\n List is empty. No position available.");
                    getch();
                    break;
                }
                temp = allocate();
                if(temp == NULL) {
                    printf("\n Overflow!!! Insufficient memory.");
                    getch();
                    break;
                }
                insert_after(&h1, temp, position);
                break;

            case 4:
                // Delete the first node
                delete_beg(&h1);
                break;

            case 5:
                // Delete the last node
                delete_end(&h1);
                break;

            case 6:
                // Delete a node at a specific position
                if(h1.first != NULL) {
                    do {
                        printf("\n Enter the position (1-%d): ", h1.count);
                        scanf("%d", &position);
                    } while(position <= 0 || position > h1.count);
                } else {
                    printf("\n List is empty. No position available.");
                    getch();
                    break;
                }
                delete_position(&h1, position);
                break;

            case 7:
                // Traverse the list
                traversal(&h1);
                break;

            case 8:
                // Search by roll number
                if(h1.first != NULL) {
                    printf(" Enter roll number to search: ");
                    scanf("%d", &number);
                    searching(&h1, number);
                } else {
                    printf("\n List is empty. No search possible.");
                    getch();
                }
                break;

            case 9:
                // Display the count of nodes
                printf("\n Total nodes: %d", h1.count);
                getch();
                break;

            case 10:
                // Exit
                printf("\n Exiting...");
                getch();
                exit(0);

            default:
                printf("\n Invalid choice! Please enter between 01 and 10.");
                getch();
        } // end of switch

    } while(choice != 10); // end of do-while loop
} // end of main()

// Allocate memory for a new student node and initialize it
struct student *allocate() {
    struct student *ptr = (struct student *)malloc(sizeof(struct student));

    if(ptr != NULL) {
        printf("\n Enter roll number (00 - 99): ");
        scanf("%d", &ptr->roll);

        printf("\n Enter sex (m / f): ");
        flushall();
        scanf(" %c", &ptr->sex);  // Added space to skip newline character

        ptr->next = NULL;
    }

    return ptr;
}

// Insert a node at the beginning
void insert_beg(struct header *head, struct student *temp) {
    if (head->first == NULL) {
        // List is empty
        temp->next = temp;   // Point to itself
        head->first = temp;
    } else {
        struct student *wptr = head->first;
        while (wptr->next != head->first) {
            wptr = wptr->next;
        }
        // Insert at the beginning
        temp->next = head->first;
        wptr->next = temp;
        head->first = temp;
    }
    head->count++;
}

// Insert a node at the end
void insert_end(struct header *head, struct student *temp) {
    if (head->first == NULL) {
        // List is empty
        head->first = temp;
        temp->next = head->first;
    } else {
        struct student *wptr = head->first;
        while (wptr->next != head->first) {
            wptr = wptr->next;
        }
        // Insert at the end
        wptr->next = temp;
        temp->next = head->first;
    }
    head->count++;
    printf("\n Node inserted at the end.");
    getch();
}

// Traverse and display the list
void traversal(struct header *head) {
    if (head->first == NULL) {
        printf("\n List is empty.");
        getch();
        return;
    }

    struct student *wptr = head->first;
    do {
        printf("\n Address: %p, Roll: %d, Sex: %c, Next: %p", wptr, wptr->roll, wptr->sex, wptr->next);
        wptr = wptr->next;
    } while (wptr != head->first);

    printf("\n Traversal completed.");
    getch();
}

// Insert a node after a specific position
void insert_after(struct header *head, struct student *temp, int position) {
    struct student *wptr = head->first;
    int counter = 1;
    while (counter < position) {
        wptr = wptr->next;
        counter++;
    }
    // Insert after the specified node
    temp->next = wptr->next;
    wptr->next = temp;
    // Update last node to point to head
    struct student *last = wptr;
    while (last->next != head->first) {
        last = last->next;
    }
    last->next = head->first;
    head->count++;
}

// Delete the first node
void delete_beg(struct header *head) {
    if (head->first == NULL) {
        printf("\n Underflow!");
        getch();
        return;
    }

    struct student *temp = head->first;
	// list contains only one single list 
    if (temp->next == head->first) {
        // Only one node in the list
        head->first = NULL;
    } else {
        struct student *wptr = head->first;
        while (wptr->next != head->first) {
            wptr = wptr->next;
        }
        // Update last node to point to new first node
        wptr->next = head->first->next;
        head->first = temp->next;
    }
    free(temp);
    head->count--;
}

// Delete the last node
void delete_end(struct header *head) {
    if (head->first == NULL) {
        printf("\n Underflow!");
        getch();
        return;
    }

    struct student *temp;
    struct student *wptr = head->first;

    if (wptr->next == head->first) {
        // Only one node in the list
        temp = wptr;
        head->first = NULL;
    } else {
        while (wptr->next->next != head->first) {
            wptr = wptr->next;
        }
        // Update wptr to be the second last node
        temp = wptr->next;
        wptr->next = head->first;
    }
    free(temp);
    head->count--;
}

// Delete a node at a specific position
void delete_position(struct header *head, int position) {
    if (head->first == NULL) {
        printf("\n Underflow!");
        getch();
        return;
    }

    if (head->first->next == head->first && position == 1) {
        // Only one node in the list
        struct student *temp = head->first;
        head->first = NULL;
        free(temp);
    } else {
        struct student *wptr = head->first;
        int i = 1;
        while (i < position - 1) {
            wptr = wptr->next;
            i++;
        }
        // Delete node at position
        struct student *temp = wptr->next;
        wptr->next = temp->next;
        free(temp);
    }
    head->count--;
}

// Search for a node by roll number
void searching(struct header *head, int number) {
    struct student *wptr = head->first;
    if (wptr == NULL) {
        printf("List is empty.");
        getch();
        return;
    }
    do {
        if (wptr->roll == number) {
            printf("Found!");
            getch();
            return;
        }
        wptr = wptr->next;
    } while (wptr != head->first);
    printf("Not Found!");
    getch();
}
