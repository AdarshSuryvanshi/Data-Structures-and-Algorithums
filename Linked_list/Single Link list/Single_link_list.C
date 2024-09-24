# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

// user defined data type
// structre definition data node
struct student
{
	int roll;
	char sex;
	// dedicated pointer variable *next to keep address of next data node
	struct student * next;
};

// structure definition for header node
struct header
{
	struct student * first; //mandatory member to store address of first data node

	//suuplimetary information
	int count;
};

//function signature interface
// return_datatype function_name(input_parameter_datatype)
struct student * allocate(void);
void insert_beg(struct header *, struct student *);
void insert_end(struct header *, struct student *);
void traversal(struct header *);
void delete_beg(struct header *);
void delete_end(struct header *);
void delete_position(struct header *, int);

void insert_after(struct header *, struct student *, int);
void searching ( struct header *, int );


void main()
{
		int choice, position,number;
	// DEDICATED POINTER VARIABLE TO HOLD MEMORY ADDRESS
	// RETURNED BY MALLOC()
	struct student * temp;

	// declaration of header node
	struct header h1;

	// initialise header variable
	h1.first = NULL;
	h1.count = 0;







	do
	{
	       clrscr();

		// Menu choice for user to play with linked list
		printf("\n ******** Menu options for Single Linked List **********\n");
		printf("\n 01. Insert the new data node at the beginning of the list.");
		printf("\n 02. Insert the new data node at the end of the list.");
		printf("\n 03. Insert the new data node after the existing data node of the list.");
		printf("\n 04. Delete the existing data node at the beginning of the list.");
		printf("\n 05. Delete the existing data node at the end of the list.");
		printf("\n 06. Delete the existing data node at particular position of the list.");
		printf("\n 07. Traversal of the list.");
		printf("\n 08. Search data node using Roll number as a search key.");
		printf("\n 09. Display count of data node in list.");
		printf("\n 10. Exit\n");
		printf("\n Enter your choice (01-10) - ");
		flushall();
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				//01. Insert the new data node at the beginning of the list.
				// call function allocate to check whther dynamic allocation
				// successful
					temp = allocate();

				// call insert_ll function if temp contains memory address
				//check whether dynamic memory allocation is successful or not
					if(temp == NULL)
					{
						printf("\n Overflow!!! Suffiecient memory is not available.");
						getch();

						break;
					}

					insert_beg(&h1, temp);
					break;


			case 2:
			//02. Insert the new data node at the end of the list.
				// call function allocate to check whther dynamic allocation
				// successful
					temp = allocate();

				// call insert_ll function if temp contains memory address
				//check whether dynamic memory allocation is successful or not
					if(temp == NULL)
					{
						printf("\n Overflow!!! Suffiecient memory is not available.");
						getch();

						break;
					}

					insert_end(&h1, temp);


					break;

			case 3:
			//03. Insert the new data node after the existing data node of the list.


					//check whether list is empty or not
					if(h1.first != NULL)
					{
						do
						{
							printf("\n Enter the position of existing data node after which yiu need to insert newly allocated data node (1-%d)- ", h1.count);
							scanf("%d", &position);
						}while((position <= 0) || (position > h1.count));
					}
					else
					{
						printf("\n List is empty. Specified position is not foound.");
						getch();
						break;
					}
					// call function allocate to check whther dynamic allocation
				// successful
					temp = allocate();

				// call insert_ll function if temp contains memory address
				//check whether dynamic memory allocation is successful or not
					if(temp == NULL)
					{
						printf("\n Overflow!!! Suffiecient memory is not available.");
						getch();

						break;
					}

					insert_after(&h1, temp, position);


					break;

			case 4:
			//04. Delete the existing data node at the beginning of the list.
					delete_beg(&h1);
					break;

			case 5:
			//05. Delete the existing data node at the end of the list.
					delete_end(&h1);

					break;

			case 6:
			//06. Delete the existing data node at particular position of the list.

					//check whether list is empty or not
					if(h1.first != NULL)
					{
						do
						{
							printf("\n Enter the position of existing data node which you need to delete (1-%d)- ", h1.count);
							scanf("%d", &position);
						}while((position <= 0) || (position > h1.count));
					}
					else
					{
						printf("\n List is empty. Specified position is not foound.");
						getch();
						break;
					}

					// call function delete_position()
					delete_position(&h1, position);

					break;

			case 7:
			//07. Traversal of the list.
					traversal(&h1);

					break;

			case 8:
			//08. Search data node using Roll number as a  search key.
						if(h1.first != NULL)
					{



						       printf(" Enter the number you want to search");
							scanf("%d", &number);
							printf(" Number to search insert succesfully");


					}
					else
					{
						printf("\n List is empty. Specified number is not foound.");
						getch();
						break;
					}
					searching (&h1 ,number);
					break;

			case 9:
			//09. Display count of data node in list.
					printf("\n Total number of data nodes availble in the list = %d", h1.count);
					getch();

					break;

			case 10:
			//10. Exit
					printf("\n Termi	nating the menu operations!!!");
					getch();
					exit(0);


			default:
						printf("\n Incorrect choice entered!!! Retry (01-09).");
						getch();
		};// end of switch

	}while(choice != 10); // end of do-while loop

}// end of main()

//function body definition
struct student * allocate()
{
	struct student * ptr;

	//initialization of ptr
	ptr = NULL;

	ptr = (struct student *) malloc(sizeof(struct student));

	// Take input from user and initialize the data node if memory allocation successful

	if(ptr != NULL)
	{
		printf("\n Enter the roll number (00 - 99)- ");
		scanf("%d", &ptr->roll);

		printf("\n Entr the sex (m / f) - ");
		flushall();
		scanf("%c", &ptr->sex);

		//initialize next field by default NULL
		ptr->next = NULL;
	}//end of if

	return(ptr);
}

void insert_beg(struct header * head, struct student * temp)
{
	  // assigning existing first data node address in * next
	  // of newly allocated data node
	  temp->next = head->first;

	  // insert newly allocated data node at the beginning of the list
	  head->first = temp;
	  head->count = head->count + 1;

}//end of insert_beg()

void insert_end(struct header * head, struct student * temp)
{
	struct student * wptr;

	//initialise wptr
	wptr = head->first;

	//check whther list is empty?
	if(head->first == NULL)
	{
		//insert newly allocatred data node at the end of the list when list is empty

		head->first = temp;
		head->count = head->count + 1;

		return;
	}

	//traverse the list to access last data node using wptr

	while(wptr->next != NULL)
	{
		//update wptr to point to next data node
		wptr = wptr->next;
	}
	//wptr is pointing to last data node
	//insert newly allocated data node at the end of the list

	wptr->next = temp;
	head->count = head->count + 1;

	printf("\n New data node is successfully inserted at the end of the list");
	getch();

	return;
}//end of insert_end()

void traversal(struct header * head)
{
	struct student * wptr;

	//initialise wptr
	wptr = head->first;

	//check whther list is empty?
	if(head->first == NULL)
	{
		printf("\n List is empty. Traversal not possible");
		getch();
		return;
	}
	//access current data node
	while(wptr->next != NULL)
	{
		//access current data node
		printf("\n Address current node- %p, Roll- %d, Sex- %c, Address next node- %p", wptr, wptr->roll, wptr->sex, wptr->next);

		//update wptr
		wptr = wptr->next;
	}

	//wptr is pointing to last data node
	//access last data node
	printf("\n Address current node- %p, Roll- %d, Sex- %c, Address next node- %p", wptr, wptr->roll, wptr->sex, wptr->next);
	printf("\n Traversal is completed.");

	getch();

	return;

}//end of traversal()

void insert_after(struct header * head, struct student * temp, int position)
{
	struct student * wptr;
	int counter;

	counter = 1;

	//initialise wptr
	wptr = head->first;

	//update wptr till it is not pointing to specified position data node
	while(counter != position)
	{
		//update wptr
		wptr = wptr->next;

		//update counter
		counter = counter + 1;
	}

	//wptr is pointig to specified position data node
	temp->next = wptr->next;
	wptr->next = temp;

	head->count = head->count + 1;

	return;
}
void delete_beg(struct header * head)
{
	struct student *temp;

	//check whther list is empty or not
	if(head->first == NULL)
	{
		printf("\n Underflow!!!!");
		getch();
		return;
	}

	//delete the data node at the beginning
	temp = head->first;
	head->first = temp->next;

	temp->next = NULL;

	free(temp);
	head->count = head->count - 1;

	return;
}
void delete_end(struct header * head)
{
	struct student *temp, *wptr;
	wptr = NULL;

	//check whther list is empty or not
	if(head->first == NULL)
	{
		printf("\n Underflow!!!!");
		getch();
		return;
	}

	//Initialize wptr to point to first data node
	wptr = head->first;


	// check whther list contain only one data node
	if(wptr->next == NULL)
	{
		//update temp to point to last data node
		temp = wptr;

		//update header node *first member
		head->first = NULL;

		//delete the previously last data node which is removed
		free(temp);
		head->count = head->count - 1;

		return;
	}

	//list is not empty and list contain more than one data node

	//traverse the list to reach to second last data node
	while(wptr->next->next != NULL)
	{
		wptr = wptr->next;
	}

	//wptr is pointing to second last data node
	//update temp to point to last data node
	temp = wptr->next;

	//update second last data node *next member to NULL
	wptr->next = NULL;

	//delete the previously last data node which is removed
	free(temp);
	head->count = head->count - 1;

	return;
}
void delete_position(struct header * head, int position)
{
	struct student * wptr;
	struct student * temp;
	int counter;

	counter = 1;

	//initializze wptr to point to first data node
	wptr = head->first;
	if ( wptr-> next == NULL)
	{
		temp = wptr;
		temp-> next = wptr-> next;
		free(temp);
		head-> count = head-> count-1;
	}
	while ( counter<(position-1))
	{
		wptr= wptr-> next;
		counter++;
	}

		temp = wptr-> next;
		wptr->next = temp-> next;
		temp->next = NULL;
		free(temp);
		head-> count = head-> count-1;









	// locate data node of specified position


}

void searching(struct header * head ,int  number)

{ 	struct student * wptr;
	wptr =head -> first;
	printf(" Adress of 1st data node :-%p",wptr);

	while ( wptr ->next!= NULL)
	{
		if (wptr-> roll== number)
		{
			printf(" Yes ");
			break;
		}

		wptr = wptr -> next;
	}
	if ( wptr -> roll== number)
	{	printf(" Yes") ;

	}
	else {
	printf(" No");
	}
}