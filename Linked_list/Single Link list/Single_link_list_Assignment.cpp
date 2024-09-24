# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
#include<string.h>
// user defined data type
// structre definition data node
struct student
{
	int roll;
	char fname[20];
	// dedicated pointer variable *next to keep address of next data node
	struct student * next;
};

// structure definition for header node
struct header
{
	struct student * first; //mandatory member to store address of first data node
	struct student * last;
	struct student * recent;
	//suuplimetary information
	int count;
};

//function signature interface
// return_datatype function_name(input_parameter_datatype)
struct student * allocate(void);
void insert_fname(struct header *, struct student *);
void traversal(struct header *);
void delete_position(struct header *, int);
void search_roll(struct header *, int);
void search_fname(struct header *, char);


void main()
{
	// DEDICATED POINTER VARIABLE TO HOLD MEMORY ADDRESS
	// RETURNED BY MALLOC()
	struct student * temp;

	// declaration of header node
	struct header h1;

	// initialise header variable
	h1.first = NULL;
	h1.count = 0;



	int choice, position;

	clrscr();

	do
	{
		clrscr();

		// Menu choice for user to play with linked list
		printf("\n ******** Menu options for Single Linked List **********\n");
		printf("\n 01. Insert the new data node as per the ascending order of fname");
		printf("\n 02. Delete the existing data node at particular position of the list.");
		printf("\n 03. Update data node.");
		printf("\n 04. Traversal of the list.");
		printf("\n 05. Access recently added data node.");
		printf("\n 06. Search data node using Roll number as a search key.");
		printf("\n 07. Search data node using First name as a search key.");
		printf("\n 08. Exit\n");
		printf("\n Enter your choice (01-08) - ");
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

					insert_fname(&h1, temp);
					break;
			case 2:
			     //02. Delete the existing data node at particular position of the list.

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
			case 3:
			     //03 Update the data node
			       break;
			case 4:
			//07. Traversal of the list.
					traversal(&h1);

					break;
			case 5:
			//05. Access the recently added data node
			// call function allocate to check whther dynamic allocation
			// successful


			      printf("\n Acessing recent data node-%p",h1.recent);
			      getch();
			      break;
			case 6:
			//06. Search data node using Roll number as a search key.
			      // check whether the list is empty
			      if(h1.first!= NULL)
			      {
				  int roll_no;
				  printf("\n Enter the roll no to search:");
				  scanf("%d",&roll_no);
				  // function calling
				  search_roll(&h1, roll_no);
			      }
			      else
			      {
				  printf("\n List is empty. Search is not possible .");
				  getch();
			      }
					break;

			case 7:
			      //07. Search data node using First name as a search key.
			      // check whether the list is empty
			      if(h1.first!= NULL)
			      {
				  char first_name;
				  printf("\n Enter the first_name to search:");
				  flushall();
				  scanf("%s",&first_name);
				  // function calling
				  search_fname(&h1, first_name);
			      }
			      else
			      {
				  printf("\n List is empty. Search is not possible .");
				  getch();
			      }
					break;

			case 8:
			//08. Exit
					printf("\n Termi	nating the menu operations!!!");
					getch();
					exit(0);


			default:
						printf("\n Incorrect choice entered!!! Retry (01-09).");
						getch();
		};// end of switch

	}while(choice != 8); // end of do-while loop

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

		printf("\n Enter your first name - ");
		flushall();
		scanf("%s", &ptr->fname);

		//initialize next field by default NULL
		ptr->next = NULL;
	}//end of if

	return(ptr);
}

void insert_fname(struct header * head, struct student * temp)
{
	  struct student * wptr;
	  // assigning first data node in an empty data node
	  // of newly allocated data node
	  if(head->first==NULL)
	  {
	     temp->next = head->first;

	     // insert newly allocated data node at the beginning of the list
	     head->first = temp;
	     head->count = head->count + 1;
	  }
	  else
	  {
		if(strcmp(temp->fname,head->first->fname)<0 )
		{
		    temp->next = head->first;

		    // insert newly allocated data node at the beginning of the list
		    head->first = temp;

		    head->count = head->count + 1;
		}
		else
		{
		     wptr=head->first;
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
		     head->recent=temp;
		     return;
		}
	  }
}//end of insert_beg()


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
		printf("\n Address current node- %p, Roll- %d, First Name- %s, Address next node- %p", wptr, wptr->roll, wptr->fname, wptr->next);

		//update wptr
		wptr = wptr->next;
	}

	//wptr is pointing to last data node
	//access last data node
	printf("\n Address current node- %p, Roll- %d, First Name- %s, Address next node- %p", wptr, wptr->roll, wptr->fname, wptr->next);
	printf("\n Traversal is completed.");

	getch();

	return;

}//end of traversal()

void delete_position(struct header * head, int position)
{
	struct student * wptr;
	struct student * temp;
	int counter;

	counter = 1;

	// initializze wptr to point to first data node
	wptr = head->first;
	if(head->first==NULL)
	{
	      printf("\n Underflow!!!!");
	      getch();
	      return;
	}
	if(position==1)
	{
	   wptr=head->first;
	   while(wptr->next !=NULL)
	   {
		wptr=wptr->next;
	   }
	   //delete the data node at the beginning
	   temp = head->first;
	   head->first = temp->next;
	   head->last=wptr;
	   temp->next = NULL;

	   free(temp);
	   head->count = head->count - 1;
	   return;
	}
	// Traverse to the node before the position to be deleted
	while(counter < position-1 && wptr->next != NULL)
	{
	      wptr=wptr->next;
	      counter++;
	}
	// If position is reachable or not
	if(counter == position-1)
	{
	      // Check if the node to be deleted is at the end
	      if(wptr->next == NULL)
	      {
		   printf("\n Position out of bounds.");
		   getch();
		   return;
	      }
	      temp=wptr->next;
	      wptr->next=temp->next;
	      // check if traversal to the last data node is successfull
	      // if yes point the first to wptr

	      // delete data node from position
	      free(temp);
	      head->count=head->count-1;
	}
	else
	{
	      printf("\n Position is not reachable.");
	      getch();
	}
}
void search_roll(struct header *head, int roll_no)
{
      // check whether the list is empty
      if(head->first== NULL)
      {
	  printf("\n The list is empty. Search not possible.");
	  getch();
	  return;
      }
      struct student *wptr=head->first;
      int target=0;

      do
      {
	   if(wptr->roll == roll_no)
	   {
		printf("\n Node found");
		target=1;
		break;
	   }
	   wptr=wptr->next;
      }while(wptr !=NULL);
      if(target==0)
      {
	   printf("\n Node not found");
      }
      getch();
}
void search_fname(struct header *head, char fname)
{
      // check whether the list is empty
      if(head->first== NULL)
      {
	  printf("\n The list is empty. Search not possible.");
	  getch();
	  return;
      }
      struct student *wptr=head->first;
      int target=0;

      do
      {
	   if((char)wptr->fname == fname)
	   {
		printf("\n Node found");
		target=1;
		break;
	   }
	   wptr=wptr->next;
      }while(wptr !=NULL);
      if(target==0)
      {
	   printf("\n Node not found");
      }
      getch();
}