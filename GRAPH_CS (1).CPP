# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# define SIZE 15

// user defined data type
// structre definition vertex data node
struct city
{
	//vertex data node information
	int cid;
	char cname[SIZE];
	int population;

	// dedicated pointer variable *vnext to keep address of next vertex data node
	struct city * vnext;

	// dedicated pointer variable * to keep address of first edge data node
	struct aroute * efirst;

	//supplimentary information of vertex data node
	int ecount;
};

// structre definition edge data node
struct aroute
{
	float air_dist;
	float duration;
	float cost;

	// dedicated pointer variable *next to keep address of destination vertex data node
	struct city *destination;

	// dedicated pointer variable *next to keep address of next edge data node
	struct aroute *enext;
};

// structure definition for graph header node
struct header
{
	struct city *vfirst; //mandatory member to store address of
									//first vertex data node

	//suplimetary information
	int vcount;
	int egcount;
};

//function signature interface
// return_datatype function_name(input_parameter_datatype)
struct city * city_allocate(void);
struct aroute * aroute_allocate(void);
void insert_city(struct header *, struct city *);
void insert_aroute(struct header *, struct city *, struct aroute *);
void traversal_dfs(struct header *);
void traversal_bfs(struct header *);
void delete_city(struct header *, int);//int cid
void delete_aroute(struct header *, struct city_source, struct city_destination *);
struct city * search_city(struct header *, int);//int cid_source
int search_aroute(struct header *, int, int);//int cid_source, int cid_destination

void main()
{
	// DEDICATED POINTER VARIABLE TO HOLD MEMORY ADDRESS
	// RETURNED BY MALLOC()
	struct city * vtemp;
	struct aroute * etemp;

	// declaration of header node  of graph
	struct header h1;

	// declaration of dedicated variables to store source and destination
	// vertex city_id
	int source_city_id, destination_city_id;

	// declaration of dedicated pointer variables to store
	// address of source and destination vertex data node
	struct city * ptr_source_city, * ptr_destination_city;

	// initialise header variable
	h1.vfirst = NULL;

	h1.vcount = 0;
	h1.egcount = 0;

	int choice;

	clrscr();

	do
	{
		clrscr();

		// Menu choice for user to play with Graph using linked list
		printf("\n ******** Menu options for Graph using Linked List **********\n");
		printf("\n 01. Insert the new City data node.");
		printf("\n 02. Insert the  new Air_Route edge data node.");
		printf("\n 03. Delete the City data node.");
		printf("\n 04. Delete the Air_Route edge data node.");
		printf("\n 05. Traversal Depth First Search (DFS).");
		printf("\n 06. Traversal Breadth First Search (BFS).");
		printf("\n 07. Search City.");
		printf("\n 08. Search Air Route between Souce and Destination City.");
		printf("\n 09. Search Shortest Air Route between Souce and Destination City.");//Assignment-08
		printf("\n 10. Search Cheapest Air Route between Souce and Destination City.");//Assignment-08
		printf("\n 11. Search All possible Air Route between Souce and Destination City.");//Assignment-08
		printf("\n 12. Display count of City in Graph.");
		printf("\n 13. Display count of Edges in Graph.");
		printf("\n 14. Display count of Air Routes of Specified Source City.");
		printf("\n 15. Exit\n");
		printf("\n Enter your choice (01-15) - ");
		flushall();
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				//01. Insert the new City data node.
				// call function allocate to check whther dynamic allocation
				// successful
					vtemp = city_allocate();

				// call insert_ll function if temp contains memory address
				//check whether dynamic memory allocation is successful or not
					if(vtemp == NULL)
					{
						printf("\n Overflow!!! Suffiecient memory is not available.");
						getch();

						break;
					}

					insert_city(&h1, vtemp);
					break;

			case 2: //02. Insert the  new Air_Route edge data node.

					// Take input from user city_id for source vertex
					clrscr();

					printf("\n Enter City_id of Source vertex - ");
					scanf("%d", &source_city_id);

					printf("\n Enter City_id of Destination vertex - ");
					scanf("%d", &destination_city_id);

					//Search for Source vertex data node in vertex list
					// matching with source city_id
					ptr_source_city = search_city(&h1, source_city_id);

					//check whther source vertex exists in the graph
					if(ptr_source_city == NULL)
					{
						printf("\n Source vertex not found. Insert Edge data node aborted!!!");
						getch();
						break;
					}

					//Search for destination vertex data node in vertex list
					// matching with source city_id
					ptr_destination_city = search_city(&h1, destination_city_id);

					//check whther destination vertex exists in the graph
					if(ptr_destination_city == NULL)
					{
						printf("\n Destination vertex not found. Insert Edge data node aborted!!!");
						getch();
						break;
					}

				//02. Insert the new aroute data node.
				// call function allocate to check whther dynamic allocation
				// successful
					etemp = aroute_allocate();

				// call insert_ll function if temp contains memory address
				//check whether dynamic memory allocation is successful or not
					if(etemp == NULL)
					{
						printf("\n Overflow!!! Suffiecient memory is not available.");
						getch();

						break;
					}

					// initialize 'destination' member of
					// newlly allocarted aroute edge data node
					etemp->destination = ptr_destination_city;


					insert_aroute(&h1, ptr_source_city, etemp );



					break;



			case 3://03. Delete the City data node.

					break;

			case 4://04. Delete the Air_Route edge data node.

					break;

			case 5://05. Traversal Depth First Search (DFS).

					break;

			case 6://06. Traversal Breadth First Search (BFS)

					break;

			case 7://07. Search City.

					break;

			case 8://08. Search Air Route between Souce and Destination City.

					break;

			case 9://09. Search Shortest Air Route between Souce and Destination City.

					break;

			case 10://10. Search Cheapest Air Route between Souce and Destination City.

					break;

			case 11://11. Search All possible Air Route between Souce and Destination City.

					break;

			case 12://12. Display count of City in Graph

					break;

			case 13://13. Display count of Edges in Graph.

					break;

			case 14://14. Display count of Air Routes of Specified Source City.

					break;
			/*
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
						printf("\n Underflow!!! List is empty.");
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
			//08. Search data node using Roll number as a search key.

					break;

			case 9:
			//09. Display count of data node in list.
					printf("\n Total number of data nodes availble in the list = %d", h1.count);
					getch();

					break;
			*/
			case 15:
			//10. Exit
					printf("\n Terminating the menu operations!!!");
					getch();
					exit(0);


			default:
						printf("\n Incorrect choice entered!!! Retry (01-09).");
						getch();
		};// end of switch

	}while(choice != 15); // end of do-while loop

}// end of main()



//function signature interface
// return_datatype function_name(input_parameter_datatype)
struct city * city_allocate(void)
{
	struct city * ptr_city;

	//initialization of ptr
	ptr_city = NULL;

	ptr_city = (struct city *) malloc(sizeof(struct city));

	// Take input from user and initialize the data node if memory allocation successful

	if(ptr_city != NULL)
	{
		printf("\n Enter the City_Id (00 - 99)- ");
		scanf("%d", &ptr_city->cid);

		printf("\n Entr the City name - ");
		flushall();
		gets(ptr_city->cname);

		printf("\n Enter the City Population- ");
		scanf("%d", &ptr_city->population);


		//initialize next vertext field by default NULL
		ptr_city->vnext = NULL;

		//initialize addtress of first edge data node
		ptr_city->efirst = NULL;

		//initialization of supplimentary information
		ptr_city->ecount = 0;
	}//end of if

	return(ptr_city);
}

struct aroute * aroute_allocate(void)
{
	struct aroute * ptr_aroute;

	//initialization of ptr
	ptr_aroute = NULL;

	ptr_aroute = (struct aroute *) malloc(sizeof(struct aroute));

	// Take input from user and initialize the data node if memory allocation successful

	if(ptr_aroute != NULL)
	{
		printf("\n Enter the air distrance (100.00 - 9999.99 Miles)- ");
		scanf("%f", &ptr_aroute->air_dist);

		printf("\n Entr the flight duration (HH.MM)- ");
		scanf("%f", &ptr_aroute->duration);

		printf("\n Enter the Flight Cost- ");
		scanf("%d", &ptr_aroute->cost);


		//initialize next vertext field by default NULL
		ptr_aroute->destination = NULL;

		//initialize addtress of first edge data node
		ptr_aroute->enext = NULL;

	}//end of if

	return(ptr_aroute);
}


//01. Insert the new City data node.(at the end of vertex list)
void insert_city(struct header * head, struct city * new_city)
{
	struct city * wptr;

	//initialise wptr
	wptr = head->vfirst;

	//check whther city vertex list is empty?
	if(head->vfirst == NULL)
	{
		//insert newly allocatred data node at the end of the list when list is empty

		head->vfirst = new_city;
		head->vcount = head->vcount + 1;

		return;
	}

	//traverse the city vertex list to access last vertex data node using wptr

	while(wptr->vnext != NULL)
	{
		//update wptr to point to next data node
		wptr = wptr->vnext;
	}
	//wptr is pointing to last data node
	//insert newly allocated data node at the end of the list

	wptr->vnext = new_city;
	head->vcount = head->vcount + 1;

	printf("\n New City vetext data node is successfully inserted at the end of the list");
	getch();

	return;
}

//07. Search City.
struct city * search_city(struct header * head, int city_id)//int cid
{
	struct city * wptr;

	//initialise wptr
	wptr = head->vfirst;

	//check whther city vertex list is empty?
	if(head->vfirst == NULL)
	{
		printf("\n Entered City Vertex data node having City Id = %d not found", city_id);
		getch();

		return(NULL);
	}

	//traverse the city vertex list to search input city vertex data node using wptr

	while((wptr->vnext != NULL) && (wptr->cid != city_id))
	{
		//update wptr to point to next data node
		wptr = wptr->vnext;
	}
	//wptr is pointing to either last city vertex data node
	// or wptr is pointing to city vertex data node containing matching city_id value with wptr->cid member
	if(wptr->cid == city_id)
	{
		printf("\n Entered City Vertex data node having City Id = %d is found having City Vertex data address = %p", city_id, wptr);
		getch();

		return(wptr);
	}

	// No city veryex data node found in vertex list in graph
	printf("\n Entered City Vertex data node having City Id = %d not found", city_id);
	getch();

	return(NULL);
}


void insert_aroute(struct header * head, struct city * ptr_source_city, struct aroute * ptr_aroute)
{
	//insert newly allocated aroute edge data node
	ptr_aroute->enext = ptr_source_city->efirst;

	ptr_source_city->efirst = ptr_aroute;

	ptr_source_city->ecount = ptr_source_city->ecount + 1;

	head->egcount = head->egcount + 1;

	return;
}
/* graph functions
void traversal_dfs(struct header *)
{
}

void traversal_bfs(struct header *)
{
}

void delete_city(struct header *, int)//int cid
{
}

void delete_aroute(struct header *, struct city_source, struct city_destination *)
{
}


int search_aroute(struct header *, int, int)//int cid_source, int cid_destin
{
}
/*

/*
//function body definition

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
	struct student * wptr, *temp;
	int counter;

	counter = 1;

	//initializze wptr to point to first data node
	wptr = head->first;

	//check whther list contains only one data node
	if(wptr->next == NULL)
	{
		//assign memory address of data node to be deleted to temp
		temp = wptr;
		head->first = wptr->next;

		free(temp);
		head->count = head->count - 1;

		return;
	}

	//list contains more than one data node
	// locate data node of specified position
	while(counter < (position - 1))
	{
		// update wptr to point to next data node
		wptr = wptr->next;

		//update counter
		counter = counter + 1;
	}
	//wptr is pointing to data node pointing to node to be deleted
	//assign memory address of data node to be deleted to temp
		temp = wptr->next;
		wptr->next = temp->next;
		temp->next = NULL;


		free(temp);
		head->count = head->count - 1;

		return;
}

int search_roll(struct header * head, int key)
{




}
*/
