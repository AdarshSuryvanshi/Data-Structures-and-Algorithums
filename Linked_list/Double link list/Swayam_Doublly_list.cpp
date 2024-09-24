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
	
// Function signatures interfcae
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
{	// pointer variable to store memory address of newly allocated data node

    struct student *temp;
    struct header h1;

    // Initialize first and count
    h1.first = NULL;
    h1.count = 0;

    int choice, position;

    

    do	//start of do while loop
    {
        
        // Menu choice for user to interact with in a  doubly linked list
        printf("\n ---------- Menu options for Double  Linked List ----------\n");
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
            //check whether memory allocation is successfull or not

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
                    // between 1 and total no of data nodes
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
                    //between 1 and total no of data nodes

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
    } while (choice != 10);// end of do while loop
}

struct student *allocate(void)
{	// dedicated pointer variable to store memory address of newly allocated
	// data node

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
        ptr->prev = NULL; // Initialize the prev pointer
    }
    // returns memory address of newly allocated data node

    return ptr;
}

void insert_beg(struct header *head, struct student *temp)
{	//checking if the list is empty or not
    if (head->first == NULL)
    {	
    	// list is empty store the address of first data node in first
    
        head->first = temp;
    }
    else
    {	// store the next data node address in first 
        temp->next = head->first;
        //	point previous data node of newly allocated data node to
        //	previoud first data node
        head->first->prev = temp;
        // inseting newly allocated data node at the beginning of the list 
        head->first = temp;
    }
    // update count 
    head->count++;
}

void insert_end(struct header *head, struct student *temp)
{	
	//	checking if the list is empty or not 
    if (head->first == NULL)
    {	
    	//inserting at the beginning of the list 
        head->first = temp;
    }// inserting at the end 
    else
    {	
    	//declaring last
        struct student *last ;
        //initializing last
        last = head->first;
        // pointing last to the last data node 
        while (last->next != NULL)
        {	
			// updating last 
            last = last->next;
        }
        //pointing the last data node to newly allocated data node 
        last->next = temp;
        //pointing the prev pointer of newly allocated data node at the 
        // last pointer variable of last data node 
        temp->prev = last;
    }
    // update count 
    head->count++;
}

void traversal(struct header *head)
{	
	//checking if the list is empty or not 
    if (head->first == NULL)
    {
        printf("\n List is empty. Traversal not possible");
        getch();
        return;
    }
    //declaring wptr  
    struct student *wptr;
    // initialize wptr 
    wptr = head->first;
    //pointing wptr to the last data node 
    while (wptr != NULL)
    {	
		// printing information
        printf("\n Address of current node- %p, Roll- %d, Sex- %c, Address of next node- %p, Address of previous node- %p", wptr, wptr->roll, wptr->sex, wptr->next, wptr->prev);
        //updating wptr 
		wptr = wptr->next;
    }
    printf("\n Traversal is completed.");
    getch();
}

void insert_after(struct header *head, struct student *temp, int position)
{	
	
	//declare wptr 
    struct student *wptr ;
    //initialize wptr 
    wptr = head->first;
    //initialize counter 
    int counter = 1;
	//counter is less than position  
    while (counter < position && wptr->next != NULL)
    {	
		// update wptr 
        wptr = wptr->next;
        //update counter 
        counter++;
    }
	// if counter reaches position
    if (counter == position)
    {	// wptr is pointing towards position 
		// inserting newly allocated data node in the position 
        temp->next = wptr->next;
     	// newly allocated data node is pointing toward wptr   
        temp->prev = wptr;
        //wptr is not pointing toward last data node
        if (wptr->next != NULL)
        {
            wptr->next->prev = temp;
        }
        // The next in position is updated to temp 
        wptr->next = temp;
    }
    else
    {
        printf("\n Position out of bounds.");
        getch();
    }
    //update count
    head->count++;
}

void delete_beg(struct header *head)
{	
	// check whether list is empty or not 
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
    // Update the first pointer to point toward next 
    head->first = temp->next;
    // checking whether list is empty or not 
    if (head->first != NULL)
    {	
    	// there is no previous data node 
        head->first->prev = NULL;
    }
    // delete data node 
    free(temp);
    //update count
    head->count--;
}

void delete_end(struct header *head)
{
	//checking whether list is empty or not 
    if (head->first == NULL)
    {
        printf("\n Underflow!!!!");
        getch();
        return;
    }
    //declare last
    struct student *last;
    // initialize last to point the first data node 
    last = head->first;
    // checking whether last is the final node of list 
    if (last->next == NULL)
    {	
		// updating first to NULL	
        head->first = NULL;
    }
    else
    {	
    	// travering until final node 
        while (last->next != NULL)
        {	
        	//updating last
            last = last->next;
        }
        //last data node is reached 
        //set the last to NULL  
        last->prev->next = NULL;
    }
    // delete the last data node 
    free(last);
    //update count 
    head->count--;
}

void delete_position(struct header *head, int position)
{	
	 // declare wptr 
    struct student *wptr;
    // initialize wptr to point toward first 
    wptr = head->first;
    // initialize first 
    int counter = 1;
	//checking whether list is empty or not 
    if (head->first == NULL)
    {
        printf("\n Underflow!!!!");
        getch();
        return;
    }
    // if position is at the beginning of the list 
    if (position == 1)
    {	
		// function calling 
        delete_beg(head);
        return;
    }
   
	// position between 1 and no of data node 
    while (counter < position && wptr->next != NULL)
    {	
		// update wptr 
        wptr = wptr->next;
        // update counter 
        counter++;
    }
	//position has been reached 
	//checking if we have successfully reached position 
    if (counter == position)
    {	// pointing next of the previous data node to 
    	// data node at the position
        wptr->prev->next = wptr->next;
        //if the position is not NULL 
        if (wptr->next != NULL)
        {	
        	// updating prev of the data node after position to point at the data node before position
            wptr->next->prev = wptr->prev;
        }
        // deleting the data node 
        free(wptr);
        //updating the previous data node 
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
	// checking whether the list is empty or not 
    if (head->first == NULL)
    {
        printf("\n The list is empty. Search not possible.");
        getch();
        return;
    }
	//declare wptr 
    struct student *wptr ;
    //initialize wptr 
    wptr = head->first;
    //initialize target 
    int target = 0;
	// while there are data node in list 
    while (wptr != NULL)
    {	//checking for specified roll no
        if (wptr->roll == roll_no)
        {	
            printf("\n Node found ");
            //when roll no is found 
            target = 1;
            break;
        }
        //updating wptr 
        wptr = wptr->next;
    }//end of while loop
	// checking if target roll no is found or not 
    if (target == 0)
    {
        printf("\n Node not found.");
    }

    getch();
}

