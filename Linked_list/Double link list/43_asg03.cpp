#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// User-defined data type
// Structure definition for a data node in a doubly linked list
struct student {
    int roll;                // Roll number of the student
    char sex;                // Sex of the student (e.g., 'm' or 'f')
    struct student *next;    // Pointer to the next node in the list
    struct student *prev;    // Pointer to the previous node in the list
};

// Structure definition for the header node
struct header {
    struct student *first;   // Pointer to the first node in the list
    int count;               // Count of nodes in the list
};

// Function prototypes
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
    int choice, position, number;  // Variables for menu choice, position, and search number
    struct student *temp;           // Pointer to hold newly allocated student node
    struct header h1;              // Header node to manage the list

    // Initialize header
    h1.first = NULL;  // Start with an empty list
    h1.count = 0;     // Initial count of nodes is zero

    do {
        clrscr();  // Clear the screen (Turbo C++ specific)

        // Menu options for user to interact with the doubly linked list
        printf("\n ******** Menu options for Double Linked List **********\n");
        printf("\n 01. Insert the new data node at the beginning of the list.");
        printf("\n 02. Insert the new data node at the end of the list.");
        printf("\n 03. Insert the new data node after the existing data node of the list.");
        printf("\n 04. Delete the existing data node at the beginning of the list.");
        printf("\n 05. Delete the existing data node at the end of the list.");
        printf("\n 06. Delete the existing data node at a particular position of the list.");
        printf("\n 07. Traversal of the list.");
        printf("\n 08. Search data node using Roll number as a search key.");
        printf("\n 09. Display count of data nodes in list.");
        printf("\n 10. Exit\n");
        printf("\n Enter your choice (01-10) - ");
        flushall();  // Flushes the input buffer (Turbo C++ specific)
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Insert the new data node at the beginning of the list
                temp = allocate();  // Allocate memory for a new student node
                if(temp == NULL) {
                    printf("\n Overflow!!! Sufficient memory is not available.");
                    getch();
                    break;
                }
                insert_beg(&h1, temp);  // Insert the new node at the beginning
                break;

            case 2:
                // Insert the new data node at the end of the list
                temp = allocate();  // Allocate memory for a new student node
                if(temp == NULL) {
                    printf("\n Overflow!!! Sufficient memory is not available.");
                    getch();
                    break;
                }
                insert_end(&h1, temp);  // Insert the new node at the end
                break;

            case 3:
                // Insert the new data node after the existing data node of the list
                if(h1.first != NULL) {
                    do {
                        printf("\n Enter the position of existing data node after which you need to insert the new data node (1-%d)- ", h1.count);
                        scanf("%d", &position);
                    } while((position <= 0) || (position > h1.count));
                } else {
                    printf("\n List is empty. Specified position is not found.");
                    getch();
                    break;
                }
                temp = allocate();  // Allocate memory for a new student node
                if(temp == NULL) {
                    printf("\n Overflow!!! Sufficient memory is not available.");
                    getch();
                    break;
                }
                insert_after(&h1, temp, position);  // Insert the new node after the specified position
                break;

            case 4:
                // Delete the existing data node at the beginning of the list
                delete_beg(&h1);  // Remove the node at the beginning
                break;

            case 5:
                // Delete the existing data node at the end of the list
                delete_end(&h1);  // Remove the node at the end
                break;

            case 6:
                // Delete the existing data node at a particular position of the list
                if(h1.first != NULL) {
                    do {
                        printf("\n Enter the position of existing data node which you need to delete (1-%d)- ", h1.count);
                        scanf("%d", &position);
                    } while((position <= 0) || (position > h1.count));
                } else {
                    printf("\n List is empty. Specified position is not found.");
                    getch();
                    break;
                }
                delete_position(&h1, position);  // Remove the node at the specified position
                break;

            case 7:
                // Traversal of the list
                traversal(&h1);  // Display all nodes in the list
                break;

            case 8:
                // Search data node using Roll number as a search key
                if(h1.first != NULL) {
                    printf(" Enter the number you want to search: ");
                    scanf("%d", &number);
                    searching(&h1, number);  // Search for the node with the given roll number
                } else {
                    printf("\n List is empty. Specified number is not found.");
                    getch();
                }
                break;

            case 9:
                // Display count of data nodes in the list
                printf("\n Total number of data nodes available in the list = %d", h1.count);
                getch();
                break;

            case 10:
                // Exit
                printf("\n Terminating the menu operations!!!");
                getch();
                exit(0);

            default:
                printf("\n Incorrect choice entered!!! Retry (01-10).");
                getch();
        }

    } while(choice != 10);  // End of do-while loop
}

// Function to allocate memory for a new student node

struct student *allocate()
 {
    struct student *ptr = (struct student *)malloc(sizeof(struct student));  // Allocate memory for the node

    if(ptr != NULL) {
        printf("\n Enter the roll number (00 - 99)- ");
        scanf("%d", &ptr->roll);  // Read roll number

        printf("\n Enter the sex (m / f) - ");
        flushall();  // Flush the input buffer
        scanf(" %c", &ptr->sex);  // Read sex, space before %c to skip any leftover whitespace

        // Initialize next and prev pointers to NULL
        ptr->next = NULL;
        ptr->prev = NULL;
    }
    return ptr;  // Return the pointer to the newly allocated node
}

// Function to insert a node at the beginning of the list

void insert_beg(struct header *head, struct student *temp) // If the insertion happened at begining then head->first previous will stored the address of new data node i.e temp
{
    if(head->first != NULL) 
{
        // If the list is not empty, update the previous pointer of the current first node

        head->first->prev = temp;	 // If the insertion happened at begining then head->first previous will stored the address of new data node i.e temp

        temp->next = head->first;
    }
    head->first = temp;  // Set the new node as the first node
    head->count += 1;    // Increment the count of nodes
}

// Function to insert a node at the end of the list

void insert_end(struct header *head, struct student *temp) {
    struct student *wptr = head->first;  // Pointer to traverse the list

    if(head->first == NULL) {
        // If the list is empty, insert the new node as the first node
        head->first = temp;
        head->count += 1;
        return;
    }

    // Traverse to the last node
    while(wptr->next != NULL) {
        wptr = wptr->next;
    }
    wptr->next = temp;   // Link the last node to the new node
    temp->prev = wptr;   // Set the previous pointer of the new node // 
    head->count += 1;    // Increment the count of nodes
}

// Function to traverse and display the list
void traversal(struct header *head) {
    struct student *wptr = head->first;  // Pointer to traverse the list

    if(head->first == NULL) {
        printf("\n List is empty. Traversal not possible");
        getch();
        return;
    }

    // Traverse from the beginning to the end
    while(wptr != NULL) {
        printf("\n Address of current node- %p, Roll- %d, Sex- %c, Address of next node- %p, Address of prev node- %p", 
            wptr, wptr->roll, wptr->sex, wptr->prev, wptr->next);
        wptr = wptr->next;
    }
    printf("\n Traversal is completed.");
    getch();
}

// Function to insert a node after a specified position
void insert_after(struct header *head, struct student *temp, int position) {
    struct student *wptr = head->first;  // Pointer to traverse the list
    int counter = 1;  // Counter to track position

    // Traverse to the node before the specified position

    while(counter < position && wptr != NULL) { // By this loop wptr will go and stand at a second last point of a specified position...

        wptr = wptr->next;
        counter++;
    }

    if(wptr != NULL) { 
        // Insert the new node after the specified position
        temp->next = wptr->next;
        temp->prev = wptr;
        if(wptr->next != NULL) {
            wptr->next->prev = temp;
        }
        wptr->next = temp;
        head->count += 1;
    }
}

// Function to delete a node at the beginning of the list
void delete_beg(struct header *head) {
    if(head->first == NULL) { // check list is empty or not ...if it is empty it means underflow
        printf("\n Underflow!!!!");
        getch();
        return;
    }

    struct student *temp = head->first;  // Pointer to the node to be deleted
    head->first = temp->next;  // Move the first pointer to the next node
    if(head->first != NULL) {
        head->first->prev = NULL;  // Update the previous pointer of the new first node
    }
    free(temp);  // Free the memory of the deleted node
    head->count -= 1;  // Decrement the count of nodes
}

// Function to delete a node at the end of the list
void delete_end(struct header *head) {
    struct student *wptr = head->first;  // Pointer to traverse the list
    struct student *temp;  // Pointer to the node to be deleted

    if(head->first == NULL) {
        printf("\n Underflow!!!!");
        getch();
        return;
    }

    if(wptr->next == NULL) {
        // If there is only one node in the list
        free(wptr);  // Free the memory of the node
        head->first = NULL;  // List is now empty
        head->count -= 1;  // Decrement the count of nodes
        return;
    }

    // Traverse to the last node
    while(wptr->next != NULL) {
        wptr = wptr->next;
    }
    
    temp = wptr;  // Node to be deleted
    wptr->prev->next = NULL;  // Update the next pointer of the second-last node
    free(temp);  // Free the memory of the deleted node
    head->count -= 1;  // Decrement the count of nodes
}

// Function to delete a node at a specific position
void delete_position(struct header *head, int position) {
    struct student *wptr = head->first;  // Pointer to traverse the list
    struct student *temp;  // Pointer to the node to be deleted
    int counter = 1;  // Counter to track position

    if(position == 1) {
        delete_beg(head);  // Special case: deleting the first node
        return;
    }

    // Traverse to the node before the specified position
    while(counter < position - 1 && wptr != NULL) {
        wptr = wptr->next;
        counter++;
    }

    if(wptr != NULL && wptr->next != NULL) {
        temp = wptr->next;  // Node to be deleted
        wptr->next = temp->next;  // Update the next pointer of the node before the deleted node
        if(temp->next != NULL) {
            temp->next->prev = wptr;  // Update the previous pointer of the node after the deleted node
        }
        free(temp);  // Free the memory of the deleted node
        head->count -= 1;  // Decrement the count of nodes
    }
}

// Function to search for a node by roll number
void searching(struct header *head, int number) {
    struct student *wptr = head->first;  // Pointer to traverse the list

    while(wptr != NULL) {
        if(wptr->roll == number) {
            printf(" Yes ");  // Roll number found
            return;
        }
        wptr = wptr->next;  // Move to the next node
    }
    printf(" No ");  // Roll number not found
}
