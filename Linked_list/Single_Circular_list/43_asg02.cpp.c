#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Define the structure for a student node
struct student {
    int roll;                 // Roll number of the student
    char sex;                 // Sex of the student ('m' or 'f')
    struct student *next;     // Pointer to the next node in the list
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
    int choice, position, number;   // Choice for menu options, position for node operations, number for search
    struct student *temp;           // Temporary pointer for student nodes
    struct header h1;               // Header structure to manage the list

    h1.first = NULL;  // Initialize header with no nodes
    h1.count = 0;     // Initialize node count to 0

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
                temp = allocate();  // Allocate memory for new node
                if(temp == NULL) {
                    printf("\n Overflow!!! Insufficient memory.");
                    getch();
                    break;
                }
                insert_beg(&h1, temp);  // Insert new node at the beginning
                break;

            case 2:
                // Insert at the end
                temp = allocate();  // Allocate memory for new node
                if(temp == NULL) {
                    printf("\n Overflow!!! Insufficient memory.");
                    getch();
                    break;
                }
                insert_end(&h1, temp);  // Insert new node at the end
                break;

            case 3:
                // Insert after an existing node
                if(h1.first != NULL) {
                    do {
                        printf("\n Enter the position (1-%d): ", h1.count);
                        scanf("%d", &position);  // Get position for insertion
                    } while(position <= 0 || position > h1.count);
                } else {
                    printf("\n List is empty. No position available.");
                    getch();
                    break;
                }
                temp = allocate();  // Allocate memory for new node
                if(temp == NULL) {
                    printf("\n Overflow!!! Insufficient memory.");
                    getch();
                    break;
                }
                insert_after(&h1, temp, position);  // Insert new node after specified position
                break;

            case 4:
                // Delete the first node
                delete_beg(&h1);  // Delete the first node
                break;

            case 5:
                // Delete the last node
                delete_end(&h1);  // Delete the last node
                break;

            case 6:
                // Delete a node at a specific position
                if(h1.first != NULL) {
                    do {
                        printf("\n Enter the position (1-%d): ", h1.count);
                        scanf("%d", &position);  // Get position for deletion
                    } while(position <= 0 || position > h1.count);
                } else {
                    printf("\n List is empty. No position available.");
                    getch();
                    break;
                }
                delete_position(&h1, position);  // Delete node at specified position
                break;

            case 7:
                // Traverse the list
                traversal(&h1);  // Traverse and display the list
                break;

            case 8:
                // Search by roll number
                if(h1.first != NULL) {
                    printf(" Enter roll number to search: ");
                    scanf("%d", &number);  // Get roll number for search
                    searching(&h1, number);  // Search for node with given roll number
                } else {
                    printf("\n List is empty. No search possible.");
                    getch();
                }
                break;

            case 9:
                // Display the count of nodes
                printf("\n Total nodes: %d", h1.count);  // Display total number of nodes
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
    struct student *ptr = (struct student *)malloc(sizeof(struct student));  // Allocate memory for new student node

    if(ptr != NULL) {
        printf("\n Enter roll number (00 - 99): ");
        scanf("%d", &ptr->roll);  // Get roll number input

        printf("\n Enter sex (m / f): ");
        flushall();
        scanf(" %c", &ptr->sex);  // Added space to skip newline character

        ptr->next = NULL;  // Initialize next pointer to NULL
    }

    return ptr;  // Return pointer to the newly allocated node
}

// Insert a node at the beginning
void insert_beg(struct header *head, struct student *temp) {
    if (head->first == NULL) {
        // List is empty
        temp->next = temp;   // Point to itself, making it a circular list with one node
        head->first = temp;  // Set this node as the first node
    } else {
        struct student *wptr = head->first;  // Pointer to traverse the list
        while (wptr->next != head->first) {
            wptr = wptr->next;  // Traverse to the last node
        }
        // Insert at the beginning
        temp->next = head->first;  // New node points to current first node
        wptr->next = temp;         // Last node now points to the new node
        head->first = temp;        // Update head to the new node
    }
    head->count++;  // Increment count of nodes
}

// Insert a node at the end
void insert_end(struct header *head, struct student *temp) {
    if (head->first == NULL) {
        // List is empty
        head->first = temp;  // Set the new node as the first node
        temp->next = head->first;  // New node points to itself
    } else {
        struct student *wptr = head->first;  // Pointer to traverse the list
        while (wptr->next != head->first) {
            wptr = wptr->next;  // Traverse to the last node
        }
        // Insert at the end
        wptr->next = temp;      // Last node now points to new node
        temp->next = head->first;  // New node points to head, maintaining circularity
    }
    head->count++;  // Increment count of nodes
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

    struct student *wptr = head->first;  // Pointer to traverse the list
    do {
        // Display current node details
        printf("\n Address: %p, Roll: %d, Sex: %c, Next: %p", wptr, wptr->roll, wptr->sex, wptr->next);
        wptr = wptr->next;  // Move to the next node
    } while (wptr != head->first);  // Continue until we circle back to the first node

    printf("\n Traversal completed.");
    getch();
}

// Insert a node after a specific position
void insert_after(struct header *head, struct student *temp, int position) {
    struct student *wptr = head->first;  // Pointer to traverse the list
    int counter = 1;
    while (counter < position) {
        wptr = wptr->next;  // Move to the node at the specified position
        counter++;
    }
    // Insert after the specified node
    temp->next = wptr->next;  // New node points to the node after wptr
    wptr->next = temp;        // wptr now points to the new node
    // Update last node to point to head
    struct student *last = wptr;  // Pointer to find the last node
    while (last->next != head->first) {
        last = last->next;  // Traverse to the last node
    }
    last->next = head->first;  // Last node now points to head
    head->count++;  // Increment count of nodes
}

// Delete the first node
void delete_beg(struct header *head) {
    if (head->first == NULL) {
        printf("\n Underflow!");
        getch();
        return;
    }

    struct student *temp = head->first;  // Pointer to the node to be deleted
    // List contains only one node
    if (temp->next == head->first) {
        // Only one node in the list
        head->first = NULL;  // Set head to NULL since the list will be empty
    } else {
        struct student *wptr = head->first;  // Pointer to traverse the list
        while (wptr->next != head->first) {
            wptr = wptr->next;  // Traverse to the last node
        }
        // Update last node to point to new first node
        wptr->next = head->first->next;  // Last node now points to the second node
        head->first = temp->next;  // Update head to the new first node
    }
    free(temp);  // Free memory of deleted node
    head->count--;  // Decrement count of nodes
}

// Delete the last node
void delete_end(struct header *head) {
    if (head->first == NULL) {
        printf("\n Underflow!");
        getch();
        return;
    }

    struct student *temp;  // Pointer to the node to be deleted
    struct student *wptr = head->first;  // Pointer to traverse the list

    if (wptr->next == head->first) {
        // Only one node in the list
        temp = wptr;  // Node to be deleted
        head->first = NULL;  // List is now empty
    } else {
        while (wptr->next->next != head->first) {
            wptr = wptr->next;  // Traverse to the second last node
        }
        // Update wptr to be the second last node
        temp = wptr->next;  // Node to be deleted
        wptr->next = head->first;  // Second last node now points to head
    }
    free(temp);  // Free memory of deleted node
    head->count--;  // Decrement count of nodes
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
        struct student *temp = head->first;  // Node to be deleted
        head->first = NULL;  // List is now empty
        free(temp);  // Free memory of deleted node
    } else {
        struct student *wptr = head->first;  // Pointer to traverse the list
        int i = 1;
        while (i < position - 1) {
            wptr = wptr->next;  // Traverse to the node before the position to delete
            i++;
        }
        // Delete node at position
        struct student *temp = wptr->next;  // Node to be deleted
        wptr->next = temp->next;  // Node before temp now points to node after temp
        free(temp);  // Free memory of deleted node
    }
    head->count--;  // Decrement count of nodes
}

// Search for a node by roll number
void searching(struct header *head, int number) {
    struct student *wptr = head->first;  // Pointer to traverse the list
    if (wptr == NULL) {
        printf("List is empty.");
        getch();
        return;
    }
    do {
        if (wptr->roll == number) {
            printf("Found!");  // Node with the given roll number found
            getch();
            return;
        }
        wptr = wptr->next;  // Move to the next node
    } while (wptr != head->first);  // Continue until we circle back to the first node
    printf("Not Found!");  // Node with the given roll number not found
    getch();
}
