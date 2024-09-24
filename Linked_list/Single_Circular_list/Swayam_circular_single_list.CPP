#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// User-defined data type
struct student
{
	int roll;
	char sex;
	// Pointer variable *next to keep the address of the next data node
	struct student * next;
};

// Structure definition for the header node
struct header
{
	// Pointer variable to store the address of the first data node

	struct student * first;
	// supllimentary information(no of nodes in a linked list)
	int count;
};

// Function signature interface
struct student * allocate(void);
void insert_beg(struct header * , struct student * );
void insert_end(struct header * , struct student * );
void traversal(struct header * );
void delete_beg(struct header * );
void delete_end(struct header * );
void delete_position(struct header * , int);
void insert_after(struct header * , struct student * , int);
void search_roll(struct header *, int);

void main()
{  // pointer variable to store memory address of newly allocated data node
	struct student * temp;
	struct header h1;
	//initialize first
	h1.first = NULL;
	//initialize count
	h1.count = 0;

	int choice, position;

	clrscr();

	do		//start of do while loop
	{
		clrscr();

		// Menu choice for user to interact with in a circular linked list
		printf("\n ---------- Menu options for Circular Singly Linked List ----------\n");
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
		scanf("%d", & choice);

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
			insert_beg(&h1,temp);
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
			insert_end( & h1, temp);
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
				}
				// between 1 and total no of data nodes
				while ((position <= 0) || (position > h1.count));// end of do while loop
			}
			else
			{
				printf("\n List is empty. Specified position not found.");
				getch();
				break;
			}
			// function calling
			insert_after( & h1, temp, position);
			break;

		case 4:
			// deleting an data node at the beginning
			// function calling
			delete_beg( & h1);
			break;

		case 5:
			// deleting an data node at the end of list
			// function calling
			delete_end( & h1);
			break;

		case 6:
			// deleting an data node after specified position
			// check whether list is empty or not
			if (h1.first != NULL)
			{
				do
				{
					printf("\n Enter the position of the existing data node which you need to delete (1-%d)- ", h1.count);
					scanf("%d", & position);
				}
				//between 1 and total no of data nodes
				while ((position <= 0) || (position > h1.count));
			}
			else
			{
				printf("\n List is empty. Specified position not found.");
				getch();
				break;
			}
			// function calling
			delete_position( & h1, position);
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
	}
	while (choice != 10);// end of do while loop
}

struct student * allocate()
{
	// dedicated pointer variable to store memory address of newly allocated
	// data node
	struct student * ptr;
	//dynamic memory allocation using malloc function
	ptr = (struct student * ) malloc(sizeof(struct student));
	//check whether memory allocation is successfull or not
	//if yes add data to store in the data node
	if (ptr != NULL)
	{
		printf("\n Enter the roll number (00 - 99)- ");
		scanf("%d", & ptr -> roll);
		printf("\n Enter the sex (m / f) - ");
		flushall();
		scanf(" %c", & ptr -> sex);
		ptr -> next = NULL;
	}
	// returns memory address of newly allocated data node
	return ptr;
}

void insert_beg(struct header * head, struct student * temp)
{
	//checking if the list is empty or not
	if (head -> first == NULL)
	{
		// List is empty, so point temp to itself to form a circular linked list
		temp -> next = temp;
		// point the first data node to temp to complete the circlar linked list
		head -> first = temp;
	}
	else
	{
		// declare dedicated pointer variable to point towards the first data node
		// from the last data node
		struct student * last;
		// initialize pointer variable to first
		last = head -> first;
		// Traverse to find the last node
		while (last -> next != head -> first)
		{
			// update last
			last = last -> next;
		}
		// last is pointing toward the last data node
		// Insert temp at the beginning
		temp -> next = head -> first;
		//point the data node to temp
		last -> next = temp;

		head -> first = temp;
	}
	// update count
	head -> count= head->count+1;
}

void insert_end(struct header * head, struct student * temp)
{
	// check whether list is empty or not
	if (head -> first == NULL)
	{
		// List is empty, so point temp to itself to form a circular list
		temp -> next = temp;
		head -> first = temp;

	}
	else
	{
		struct student * last ;
		// initialize last
		last = head -> first;
		// Traverse to find the last node
		while (last -> next != head -> first)
		{
			// update last
			last = last -> next;
		}
		//last is pointing toward the last data node
		// Insert temp at the end
		last -> next = temp;
		temp -> next = head -> first;
	}
	head -> count= head-> count+1;
}

void traversal(struct header * head)
{
	// check whether list is empty or not
	if (head -> first == NULL)
	{
		printf("\n List is empty. Traversal not possible");
		getch();
		return;
	}
	struct student * wptr;
	// initialize wptr
	 wptr = head -> first;
	do	// start of do while loop
	{
		printf("\n Address of current node- %p, Roll- %d, Sex- %c, Address of next node- %p", wptr, wptr -> roll, wptr -> sex, wptr -> next);
		// update wptr
		wptr = wptr -> next;
	}
	while (wptr != head -> first);// end of do while loop

	printf("\n Traversal is completed.");
	getch();
}

void insert_after(struct header * head, struct student * temp, int position)
{
	// declare an walking pointer

	struct student * wptr;

	//initialize the walking pointer

	wptr = head -> first;

	int counter = 1;

	// start of while loop
	// while counter is less than input position and pointer next and first are
	// not equal
	while (counter < position && wptr -> next != head -> first)
	{
		// update wptr
		wptr = wptr -> next;
		//update counter
		counter=counter +1;
	}
	// wptr has reached  position
	if (counter == position)
	{
		temp -> next = wptr -> next;
		wptr -> next = temp;
	}
	else
	{
		printf("\n Position out of bounds.");
		getch();
	}
	head -> count=head->count+1;
}

void delete_beg(struct header * head)
{
	//check whether the list is empty or not
	if (head -> first == NULL)
	{
		printf("\n Underflow!!!!");
		getch();
		return;
	}
	struct student * temp;
	temp = head -> first;
	if (head -> first -> next == head -> first)
	{
		// list only has one data node
		head -> first = NULL;
	}
	else
	{
		struct student * last = head -> first;
		while (last -> next != head -> first)
		{
			last = last -> next;
		}
		last -> next = temp -> next;
		head -> first = temp -> next;
	}
	free(temp);
	head -> count--;
}

void delete_end(struct header * head)
{
	if (head -> first == NULL)
	{
		printf("\n Underflow!!!!");
		getch();
		return;
	}
	struct student * temp = head -> first;
	if (head -> first -> next == head -> first)
	{
		// Only one node in the list
		head -> first = NULL;
	}
	else
	{
		struct student * last = head -> first;
		while (last -> next -> next != head -> first)
		{
			last = last -> next;
		}
		temp = last -> next;
		last -> next = head -> first;
	}
	free(temp);
	head -> count--;
}
void delete_position(struct header * head, int position)
{
	if (head -> first == NULL)
	{
		printf("\n Underflow!!!!");
		getch();
		return;
	}
	if (position == 1)
	{
		delete_beg(head);
		return;
	}
	struct student * wptr = head -> first;
	struct student * temp;
	int counter = 1;

	// Traverse to the node before the position to be deleted
	while (counter < position - 1 && wptr -> next != head -> first)
	{
		wptr = wptr -> next;
		counter++;
	}

	// If position is reachable or not
	if (counter == position - 1)
	{
		// Check if the node to be deleted is at the end
		if (wptr -> next == head -> first)
		{
			printf("\n Position out of bounds.");
			getch();
			return;
		}
		temp = wptr -> next;
		wptr -> next = temp -> next;
		//check if traversal to the last data node is successfull or not
		// if yes point the first to wptr
		if (temp == head -> first)
		{
			head -> first = wptr -> next;
		}
		// delete data node from position
		free(temp);
		head -> count=head->count-1;
	}
	else
	{
		printf("\n Position is not reachable.");
		getch();
	}
}
void search_roll(struct header *head, int roll_no)
{
	 if (head->first == NULL)
	 {
		  printf("\n The list is empty. Search not possible.");
		  getch();
		  return;
	 }

	 struct student *wptr = head->first;
	 int target = 0;

	 do
	 {
		  if (wptr->roll == roll_no)
		  {
				printf("\n Node found ");
				target = 1;
				break;
		  }
		  wptr = wptr->next;
	 } while (wptr != head->first);

	 if (target ==0)
	 {
		  printf("\n Node not found.");
	 }

	 getch();
}


