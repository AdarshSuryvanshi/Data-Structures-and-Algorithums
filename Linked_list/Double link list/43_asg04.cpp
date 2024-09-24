#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// User-defined data type
// Structure definition for a data node in a circular doubly linked list
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

        // Menu options for user to interact with the circular doubly linked list
        printf("\n ******** Menu options for Circular Doubly Linked List **********\n");
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

struct student *allocate() {
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

void insert_beg(struct header *head, struct student *temp) {
    if(head->first == NULL) {
        // If the list is empty, insert the new node as the only node
        temp->next = temp;
        temp->prev = temp;
        head->first = temp;
    } else {
        // Insert at the beginning of the list
        struct student *last = head->first->prev;  // The last node in the circular list
        temp->next = head->first;  // New node's next points to the old first node
        temp->prev = last;  // New node's prev points to the last node
        head->first->prev = temp;  // Old first node's prev points to the new node
        last->next = temp;  // Last node's next points to the new node
        head->first = temp;  // Update the first pointer to the new node
    }
    head->count += 1;  // Increment the count of nodes
}

// Function to insert a node at the end of the list

void insert_end(struct header *head, struct student *temp) {
    if(head->first == NULL) {
        // If the list is empty, insert the new node as the only node
        temp->next = temp;
        temp->prev = temp;
        head->first = temp;
    } else {
        // Insert at the end of the list
        struct student *last = head->first->prev;  // The last node in the circular list
        temp->next = head->first;  // New node's next points to the first node
        temp->prev = last;  // New node's prev points to the last node
        last->next = temp;  // Last node's next points to the new node
        head->first->prev = temp;  // First node's prev points to the new node
    }
    head->count += 1;  // Increment the count of nodes
}

// Function to delete the node at the beginning of the list

void delete_beg(struct header *head) {
    if(head->first == NULL) {
        printf("\n List is empty. No node to delete.");
    } else if(head->first->next == head->first) {
        // If there is only one node
        free(head->first);  // Free the node
        head->first = NULL;  // Update the header
    } else {
        struct student *last = head->first->prev;  // The last node in the list
        struct student *temp = head->first;  // The node to be deleted
        head->first = head->first->next;  // Update the first pointer
        head->first->prev = last;  // Update the new first node's prev
        last->next = head->first;  // Update the last node's next
        free(temp);  // Free the deleted node
    }
    head->count -= 1;  // Decrement the count of nodes
}

// Function to delete the node at the end of the list

void delete_end(struct header *head) {
    if(head->first == NULL) {
        printf("\n List is empty. No node to delete.");
    } else if(head->first->next == head->first) {
        // If there is only one node
        free(head->first);  // Free the node
        head->first = NULL;  // Update the header
    } else {
        struct student *last = head->first->prev;  // The last node in the list
        struct student *new_last = last->prev;  // The new last node
        free(last);  // Free the old last node
        new_last->next = head->first;  // Update the new last node's next
        head->first->prev = new_last;  // Update the first node's prev
    }
    head->count -= 1;  // Decrement the count of nodes
}

// Function to delete the node at a specific position

void delete_position(struct header *head, int position) {
    if(head->first == NULL) {
        printf("\n List is empty. No node to delete.");
    } else if(position == 1) {
        delete_beg(head);  // Use delete_beg if deleting the first node
    } else if(position == head->count) {
        delete_end(head);  // Use delete_end if deleting the last node
    } else {
        struct student *temp = head->first;
        for(int i = 1; i < position; i++) {
            temp = temp->next;  // Traverse to the node at the given position
        }
        temp->prev->next = temp->next;  // Bypass the node to be deleted
        temp->next->prev = temp->prev;  // Bypass the node to be deleted
        free(temp);  // Free the deleted node
        head->count -= 1;  // Decrement the count of nodes
    }
}

// Function to insert a node after a specific node

void insert_after(struct header *head, struct student *temp, int position) {
    struct student *current = head->first;
    for(int i = 1; i < position; i++) {
        current = current->next;  // Traverse to the node after which to insert
    }
    temp->next = current->next;  // New node's next points to the next node
    temp->prev = current;  // New node's prev points to the current node
    current->next->prev = temp;  // Next node's prev points to the new node
    current->next = temp;  // Current node's next points to the new node
    head->count += 1;  // Increment the count of nodes
}

// Function to traverse the list and print its elements

void traversal(struct header *head) {
    if(head->first == NULL) {
        printf("\n List is empty.");
    } else {
        struct student *temp = head->first;
        do {
            printf("\n Roll number: %d, Sex: %c , Addres of current data node = %p , Addres of next data node = %p ,Adress of previous data node = %p ", temp->roll, temp->sex, temp , temp-> prev ,temp->next );  // Print node data
            temp = temp->next;  // Move to the next node
        } while(temp != head->first);  // Continue until we return to the start
    }
    getch();  // Pause to view output
}

// Function to search for a node with a specific roll number

void searching(struct header *head, int roll) {
    struct student *temp = head->first;
    do {
        if(temp->roll == roll) {
            printf("\n Node with Roll number %d found.", roll);  // Node found
            return;
        }
        temp = temp->next;  // Move to the next node
    } while(temp != head->first);  // Continue until we return to the start
    printf("\n Node with Roll number %d not found.", roll);  // Node not found
}
