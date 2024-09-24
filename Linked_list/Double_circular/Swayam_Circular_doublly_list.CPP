#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// User-defined data type
struct student
{
    int roll;
    char sex;
    // Pointer variable *next to keep the address of the next data node
    struct student *next;
    // Pointer variable *next to keep the address of the previous data node
    struct student *prev; 
};

// Structure definition for the header node
struct header
{
	// Pointer variable to store the address of the first data node

    struct student *first; 
    // supllimentary information(no of nodes in a linked list
    int count;             
};

// Function signatures interface
struct student *allocate(void);
void insert_beg(struct header *, struct student *);
void insert_end(struct header *, struct student *);
void traversal(struct header *);
void delete_beg(struct header *);
void delete_end(struct header *);
void delete_position(struct header *, int);
void insert_after(struct header *, struct student *, int);
void search_roll(struct header *, int);

void main()
{	
	// pointer variable to store memory address of newly allocated data node
	
    struct student *temp;
    struct header h1;

    // Initialize first and count
    h1.first = NULL;
    h1.count = 0;

    int choice, position;

    clrscr();

    do	//start of do while loop
    {
        clrscr();
        // Menu choice for user to interact with in a circular  double linked list
        printf("\n ---------- Menu options for Circular Double Linked List ----------\n");
        printf("\n 01. Insert the new data node at the beginning of the list.");
        printf("\n 02. Insert the new data node at the end of the list.");
        printf("\n 03. Insert the new data node after the existing data node of the list.");
        printf("\n 04. Delete the existing data node at the beginning of the list.");
        printf("\n 05. Delete the existing data node at the end of the list.");
        printf("\n 06. Delete the existing data node at a particular position of the list.");
        printf("\n 07. Traversal of the list.");
        printf("\n 08. Search data node using Roll number as a search key.");
        printf("\n 09. Display count of data nodes in the list.");
        printf("\n 10. Exit\n");
        printf("\n Enter your choice (01-10) - ");
        flushall();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        	// inserting newly allocated data node at the beginning
			//dynamic memory allocation by using malloc function
	
            temp = allocate();
            //check whether memory allocation is successfull or no
            if (temp == NULL)
            {
                printf("\n Overflow!!!");
                getch();
                break;
            }
            //function calling
            insert_beg(&h1, temp);
            break;

        case 2:
        	// inserting newly allocated data node at the beginning
			//dynamic memory allocation by using malloc function
            temp = allocate();
            //check whether memory allocation is successfull or not
            if (temp == NULL)
            {
                printf("\n Overflow!!! Memory allocation not successful");
                getch();
                break;
            }
            // function calling
            insert_end(&h1, temp);
            break;

        case 3:
        	// inserting newly allocated data node after existing data node
			//dynamic memory allocation by using malloc function

            temp = allocate();
            //check whether memory allocation is successfull or not
            if (temp == NULL)
            {
                printf("\n Overflow!!!");
                getch();
                break;
            }
            // checking whether list is empty or not
            if (h1.first != NULL)
            {
                do
                {
                    printf("\n Enter the position of existing data node after which you need to insert the new data node (1-%d)- ", h1.count);
                    scanf("%d", &position);
                } while ((position <= 0) || (position > h1.count));// end of do while loop
            }//list is empty 
            else
            {
                printf("\n List is empty. Specified position not found.");
                getch();
                break;
            }
            // function calling
            insert_after(&h1, temp, position);
            break;

        case 4:
        	// deleting an data node at the beginning
			// function calling

            delete_beg(&h1);
            break;

        case 5:
        	// deleting an data node at the end of list
			// function calling
            delete_end(&h1);
            break;

        case 6:
        	// deleting an data node after specified position
			// check whether list is empty or not

            if (h1.first != NULL)
            {
                do
                {
                    printf("\n Enter the position of the existing data node which you need to delete (1-%d)- ", h1.count);
                    scanf("%d", &position);
                } while ((position <= 0) || (position > h1.count));// end of do while 
            }
            else
            {
                printf("\n List is empty. Specified position not found.");
                getch();
                break;
            }
            // function calling
            delete_position(&h1, position);
            break;

        case 7:
        	// traversing the linked list
			// function calling

            traversal(&h1);
            break;

        case 8:
        	//searching linked list with roll no as the search key
			// check whether list is empty

            if (h1.first != NULL)
            {
                int roll_no;
                printf("\n Enter the roll number to search: ");
                scanf("%d", &roll_no);
                // function calling


                search_roll(&h1, roll_no);
            }
            else
            {
                printf("\n List is empty. Search not possible.");
                getch();
            }
            break;

        case 9:
        	// displaying total no of data nodes in a linked list

            printf("\n Total number of data nodes available in the list = %d", h1.count);
            getch();
            break;

        case 10:
        	// exit

            printf("\n Terminating linked list !!!");
            getch();
            exit(0);

        default:
            printf("\n Incorrect choice entered. Retry (01-10).");
            getch();
        }
    } while (choice != 10);
}

struct student *allocate(void)
{	
	// dedicated pointer variable to store memory address of newly allocated
	// data node
	// declare dedicated pointer variable 
	
    struct student *ptr;
    //dynamic memory allocation using malloc function

    ptr = (struct student *)malloc(sizeof(struct student));
    //check whether memory allocation is successfull or not
    //if yes add data to store in the data node

    if (ptr != NULL)
    {
        printf("\n Enter the roll number (00 - 99)- ");
        scanf("%d", &ptr->roll);
        printf("\n Enter the sex (m / f) - ");
        flushall();
        scanf(" %c", &ptr->sex);
        ptr->next = NULL;
        ptr->prev = NULL; 
    }
    // returns memory address of newly allocated data node

    return ptr;
}

void insert_beg(struct header *head, struct student *temp)
{	
	//checking if the list is empty or not

    if (head->first == NULL)
    {	
    	// list is empty store the address of first data node in first
        temp->next = temp;
        // point the prev pointer to temp to point towards itself 
        temp->prev = temp; 
        // initialize first to temp 
        head->first = temp;
    }
    else
    {	// declare pointer variable 
        struct student *last ;
        // initialize last to prev of first data node 
        last = head->first->prev;
        // inserting temp as first data node 
        temp->next = head->first;
        // making newly allocated data node  the new last node and linking it to end of list  
        temp->prev = last;
        // linking last data node to first
        last->next = temp;
        //making newly allocated data node  the data node before the previous first data node 
        head->first->prev = temp;
        //making newly allocated data node the first data node
        head->first = temp;
    }
    //update count 
    head->count++;
}

void insert_end(struct header *head, struct student *temp)
{	
	// check whether list is empty or not 
    if (head->first == NULL)
    {	
    	// list is empty 
    	// temp is pointing at itself through next
        temp->next = temp;
        //temp is pointing itself through prev 
		temp->prev = temp; 
        //insert the newly allocated data node in to list
		head->first = temp;
    }
    else
    {	// declare last 
        struct student *last;
        // initialize last 
        last = head->first->prev;
        //linking previous last data node with newly allocated data node 
        last->next = temp;
        //linking previous last data node with newly allocated data node both ways 
        temp->prev = last;
        //inserting newly allocated data node at the end of list 
        temp->next = head->first;
        //making newly allocated data node  the data node before the previous first data node 
        head->first->prev = temp;
    }
    //update count 
    head->count++;
}

void traversal(struct header *head)
{	// checking whether list is empty 
    if (head->first == NULL)
    {	
        printf("\n List is empty. Traversal not possible");
        getch();
        return;
    }
    //declare wptr 
    struct student *wptr ;
    // initialize wptr 
	 wptr = head->first;
    do
    {
        printf("\n Address of current node- %p, Roll- %d, Sex- %c, Address of next node- %p, Address of previous node- %p", wptr, wptr->roll, wptr->sex, wptr->next, wptr->prev);
 		// update wptr        
		wptr = wptr->next;
    } while (wptr != head->first);// end of do while loop

    printf("\n Traversal is completed.");
    getch();
}

void insert_after(struct header *head, struct student *temp, int position)
{	
	//declaring wptr 
    struct student *wptr;
    //initialize wptr 
    wptr = head->first;
    // declare and initialzie counter  
    int counter = 1;
	// position between 1 and total no of data node 
    while (counter < position && wptr->next != head->first)
    {	
    	//update wptr  
        wptr = wptr->next;
        //update counter 
        counter++;
    }
	// wptr is pointing toward position 
	// checking if counter and position are same 
    if (counter == position)
    {	
    	// pointing  newly allocated data node at position 
        temp->next = wptr->next;
        //linking previous data node with newly allocated data node at position 
        temp->prev = wptr;
        //////making newly allocated data node  the data node before the previous first data node 
        wptr->next->prev = temp;
        // inserting the newly allocated data node after wptr connecting the them
        wptr->next = temp;
    }
    else
    {
        printf("\n Position out of bounds.");
        getch();
    }
    // update count 
    head->count++;
}

void delete_beg(struct header *head)
{	
	//checking if the list is empty or not 
    if (head->first == NULL)
    {
        printf("\n Underflow!!!!");
        getch();
        return;
    }
    //declare temp
    struct student *temp ;
    //initialize temp 
    temp = head->first;
    // checking if  previous data node first and first is same 
	if (head->first->next == head->first)
    {	
		// initialize first to NULL
        head->first = NULL;
    }
    else
    {	
    	//declare last 
        struct student *last;
        //initialize last 
        last = head->first->prev;
        //making the data node after previous first data node the new first data node 
        head->first = temp->next;
        //pointing  prev of new first data node  to last 
        head->first->prev = last;
        //pointing last pointer to the new first data node 
        last->next = head->first;
    }
    //delete temp from linked list 
    //i.e deleting last data node from list  
    free(temp);
    //update count
    head->count--;
}

void delete_end(struct header *head)
{	
	//checking if list is empty or not 
    if (head->first == NULL)
    {
        printf("\n Underflow!!!!");
        getch();
        return;
    }
    //declare last 
    struct student *last ;
    //initialize last 
    last = head->first->prev;
    //checking if there is only one data node in linked list 
	if (last == head->first)
    {	
    	// updating first to NULL
        head->first = NULL;
    }
    else
    {	
    	//decare second_last to store address of data node before the last data node 
        struct student *second_last;
        //initialize last 
        second_last = last->prev;
        //linking the data node before the last data node to point toward first 
        second_last->next = head->first;
        //pointing the prev of first toward secound last data node 
        head->first->prev = second_last;
    }
    //deleting the last date node 
    free(last);
    //update count 
    head->count--;
}

void delete_position(struct header *head, int position)
{	
	//checking whether list is empty or not 
    if (head->first == NULL)
    {
        printf("\n Underflow!!!!");
        getch();
        return;
    }
    //if the entered position is 1 
    if (position == 1)
    {	
    	//calling the delete_beg function 
        delete_beg(head);
        return;
    }
    //declare wptr 
    struct student *wptr ;
    //initialize wptr 
 	wptr = head->first;
	//declare and initialzie counter to 1  
    int counter = 1;
	//position between 1 and total no of data node 
    while (counter < position && wptr->next != head->first)
    { 	
    	//update wptr 
        wptr = wptr->next;
        //update counter 
        counter++;
    }
    
	//if counter is equal to position 
    if (counter == position)
    {
    	//removing data node at position from list 
        wptr->prev->next = wptr->next;
        //pointing next of data node before position with data node after position
		wptr->next->prev = wptr->prev;
        //deleting data node after specified position 
		free(wptr);
        //update count 
		head->count--;
    }
    else
    {
        printf("\n Position out of bounds.");
        getch();
    }
}

void search_roll(struct header *head, int roll_no)
{
	//checking whether list is empty or not 
    if (head->first == NULL)
    {
        printf("\n The list is empty. Search not possible.");
        getch();
        return;
    }
	//declare wptr 
    struct student *wptr;
    //initialize wptr 
    wptr = head->first;
    //declare and initialize taarget 
    int target = 0;

    do
    {	
    	//searching for roll no 
        if (wptr->roll == roll_no)
        {
            printf("\n Node found ");
            //if target is found update target 
            target = 1;
            break;
        }
        wptr = wptr->next;
    } while (wptr != head->first);//end of do while loop 
	
	//if target is not found 
    if (target == 0)
    {
        printf("\n Node not found.");
    }

    getch();
}
