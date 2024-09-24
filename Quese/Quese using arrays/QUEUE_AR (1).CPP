# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# define SIZE 5
// user defined data type
// structre definition data node

struct student
{
	int roll;
	char sex;
};

struct queue
{
	struct student list[SIZE];
	int front, rear;
	int count;
};

// function signature interface
int enqueue(struct queue *, struct student *);
int dequeue(struct queue *, struct student *);
int queue_front(struct queue *, struct student *);
int queue_rear(struct queue *, struct student *);


void main()
{
	int choice, status;
	struct queue q1;
	struct student stud;   //insertion- to hold record for insertion in queue
								  //deletion- to store deleted record from queue

	//initialization of queue variable members
	q1.front = -1; //queue array is empty
	q1.rear = -1;
	q1.count = 0;



	//*** Menu
	do
	{
		clrscr();
		printf("\n ****** MENU QUEUE USING ARRAY ********");

		printf("\n 1. ENQUEUE");
		printf("\n 2. DEQUEUE");
		printf("\n 3. QUEUE_FRONT");
		printf("\n 4. QUEUE_REAR");
		printf("\n 5. Reversal of Queue elements"); //Assignment-06
		printf("\n 6. Empty Queue"); //Assignment-06
		printf("\n 7. Count of Queue data node.");
		printf("\n 8. Search the data node in queue using Roll number as key"); //Assignment-06
		printf("\n 9. Exit");
		printf("\n\n Enter the menu choice (1-9)- ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: //Enqueue
					  //Take input from user
					  printf("\n Enter the information of new record to be inserted.");
					  printf("\n\n Enter the Roll number- ");
					  scanf("%d", &stud.roll);
					  printf("\n Enter the Sex (m / f)- ");
					  flushall();
					  scanf("%c", &stud.sex);

					  status = enqueue(&q1, &stud);

					  if(status == 1)
					  {
							printf("\n Enqueue operation is successful.");
							getch();
					  }
					  else
					  {
							printf("\n Enqueue operation is not successful.");
							getch();
					  }

					  break;

			case 2: //Dequeue
					  status = dequeue(&q1, &stud);

					  if(status == 1)
					  {
							printf("\n DEQUEUE operation is successful.");
							printf("\n Deleted data node having roll - %d, sex - %c", stud.roll, stud.sex);

							getch();
					  }
					  else
					  {
							printf("\n DEQUEUE operation is not successful.");
							getch();
					  }

					  break;

			case 3: //Queue_front
					 status = queue_front(&q1, &stud);

					  if(status == 1)
					  {
							printf("\n Queue_Front operation is successful.");
							printf("\n Front data node having roll - %d, sex - %c", stud.roll, stud.sex);

							getch();
					  }
					  else
					  {
							printf("\n Queue_Front operation is not successful.");
							getch();
					  }

					 break;

			case 4: //Queue_Rear
					 status = queue_rear(&q1, &stud);

					  if(status == 1)
					  {
							printf("\n Queue_Rear operation is successful.");
							printf("\n Rear data node having roll - %d, sex - %c", stud.roll, stud.sex);

							getch();
					  }
					  else
					  {
							printf("\n Queue_Rear operation is not successful.");
							getch();
					  }

					 break;

			case 5: //reversal of queue
					  //assignment-06


					 break;

			case 6: //Empty queue
					  //assignment-06

					 break;

			case 7: //count of queue nodes
					 printf("\n Total number of data nodes in queue - %d", q1.count);
					 getch();

					 break;

			case 8: // Search
					  //assignment-06

					 break;

			case 9: //Exit
					  printf("\n Terminating the Menu");
					  getch();
					  exit(0);
					  break;

			default : //Invalid input
						printf("\n Invalild choice entered!!! Retry (1-9)");
						getch();
		}; //end of switch

	}while(choice != 9);//end of do-while
}

//function body definition

int enqueue(struct queue * pq1, struct student * stud)
{
	//updating rear to point to next adjacent memory location
	pq1->rear = (pq1->rear + 1);

	//check whether rear is pointing to  valid index position
	if(pq1->rear == SIZE)
	{
		printf("\n Overflow!!!");
		getch();

		//reset rear
		pq1->rear = pq1->rear - 1;

		return(0);
	}


	// insert the new data node in queue
	(pq1->list + pq1->rear)->roll = stud->roll;
	(pq1->list + pq1->rear)->sex = stud->sex;

	//update count of queue data nodes
	pq1->count = pq1->count + 1;

	//check whther front is pointing to -1
	if(pq1->front == -1)
	{
		pq1->front = pq1->front + 1;
	}

	return(1);
}

int dequeue(struct queue *pq1, struct student * stud)
{
	//check whther queue is empty or not
	if((pq1->front) == -1)
	{
		printf("\n Underflow!!!");
		getch();
		return(0);
	}

	//copy the members into temporaray data node
	stud->roll = ((pq1->list) + (pq1->front))->roll;
	stud->sex = ((pq1->list) + (pq1->front))->sex;

	//update the front
	pq1->front = pq1->front + 1;
	pq1->count = pq1->count - 1;

	//check whether dequeue operation resulted front to point next index position of rear
	if(pq1->front > pq1->rear)
	{
		//reset front and rear both as queue is empty
		pq1->front = -1;
		pq1->rear  = -1;
  }
	return(1);
}

int queue_front(struct queue *pq1, struct student * stud)
{
	//check whther queue is empty or not
	if((pq1->front) == -1)
	{
		printf("\n Queue is empty.");
		getch();
		return(0);
	}

	//copy the members of first data node into temporaray data node
	stud->roll = ((pq1->list) + (pq1->front))->roll;
	stud->sex = ((pq1->list) + (pq1->front))->sex;

	return(1);
}

int queue_rear(struct queue *pq1, struct student * stud)
{
	//check whther queue is empty or not
	if((pq1->front) == -1)
	{
		printf("\n Queue is empty.");
		getch();
		return(0);
	}

	//copy the members of first data node into temporaray data node
	stud->roll = ((pq1->list) + (pq1->rear))->roll;
	stud->sex = ((pq1->list) + (pq1->rear))->sex;

	return(1);
}
