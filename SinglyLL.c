#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct node
{
	int info;
	struct node *next;
}node;

node *head = NULL;

//Inserting new data in the end

void InsertAtEnd()
{
	node *ptr, *loc;

	ptr = (node *)malloc(sizeof(node));

	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	ptr->next = NULL;

	if(head == NULL) 		
	head = ptr;
	else
	{
		for(loc = head ; loc->next != NULL ; loc = loc->next);
		loc->next = ptr;
	}
}

//Inserting new data at the beginning

void InsertAtBeginning(int x)
{
	node *ptr;
	ptr = (node *)malloc(sizeof(node));
	ptr->info=x;
	ptr->next = head;
	head = ptr;
}

// searching any element
node *SearchElement(int x)  
{			    
	node *ptr;
	for(ptr = head ; ptr != NULL ; ptr = ptr->next)
	{
		if(ptr->info == x)
			return ptr;
	}
	return NULL;
}

//Inserting new data after a given node

void InsertAfterAGivenNode(int x,int a)
{
	node *ptr, *loc;

	loc = head;
	while(loc!=NULL)
	{
		if(loc->info == a)
			break;
		loc=loc->next;
	}
	if(loc==NULL)
	{
		printf("\nInvalid input");
		return;
	}
	ptr = (node *)malloc(sizeof(node));
	ptr->info=x;
	ptr->next = loc->next;
	loc->next = ptr;
}

//Delete the first node

void Delete1stNode()
{
	node *loc;
	if(head==NULL)
	{
		printf("Empty list");
	}
	else
	{
		loc=head;
		head= head->next;
		printf("\n%d is deleted.",loc->info);
	}
}

// Delete last node

void Deletelastnode()
{
	node *ptr, *prev;

	ptr = head;

	if(ptr == NULL)
	{
		printf("\n\tNot found.");
		return;
	}
	else 
	{
		while(ptr->next!=NULL)
		{
			prev=ptr;
			ptr=ptr->next;
		}
		if(ptr==head)
		{
			head=NULL;
			printf("%d node deleted",ptr->info);
			free(ptr);
		}
		else
		{
			prev->next=NULL;
			printf("%d node deleted",ptr->info);
			free(ptr);
		}
	}
}
//Delete the I-th element 

node *delete_ith(int x)
{
	int c=1;
	node *loc,*prev;
	loc=head;
	prev=NULL;
	while(loc!=NULL)
	{
		if (c==x)
		{
			if(prev==NULL)
				head=loc->next;
			else
				prev->next=loc->next;
			printf("%d node deleted",loc->info);
			free(loc);
			return head;
		}
		c++;
		prev=loc;
		loc=loc->next;
		getch();
	}
}

//Display the list

void ForwardDisplay()
{
	node *ptr;
	if(head == NULL)
	{
		printf("\n\tList empty.");
		return;
	}
		for(ptr = head ; ptr != NULL ; ptr = ptr->next)
		printf("\t%d", ptr->info);
}

//Reverse display of all nodes

void BackwardDisplay(node *ptr)
{
	if(ptr->next != NULL)
		BackwardDisplay(ptr->next);
	printf("\t%d", ptr->info);
}

//Reverse the list

void Reverselist()
{
	node *ptr,*prev,*loc;
	loc=head;
	if(loc==NULL)
	{
		printf("\n\tList empty.");
		return;	
	}
	while(loc->next!=NULL)
	{
		ptr=loc->next;
		if(loc==head)
			loc->next=NULL;
		else
			loc->next=prev;
		prev=loc;
		loc=ptr;
	}
	head=loc;
	head->next=prev;
	printf("\n List is reversed.");
}


void main()
{
	int ch,x,a,ptr;

	while(1)
	{
		

		printf("\n\tMENU.");
		printf("\n\t1. Insert At End.");
		printf("\n\t2. Insert At Beginning.");
		printf("\n\t3. Insert After A Given Node.");
		printf("\n\t4. Delete First Node.");
		printf("\n\t5. Delete Last Node.");
		printf("\n\t6. Delete I-th node.");
		printf("\n\t7. Forward Display.");
		printf("\n\t8. Backward Display.");
		printf("\n\t9. Reverse the list.");
		printf("\n\t10. Search element.");
		printf("\n\t0. Exit.");
		printf("\n\t\tEnter your choice : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1 : InsertAtEnd();
						 break;
			case 2 : printf("\n Enter value to insert at beginning :");
					 scanf("%d",&x);
					 InsertAtBeginning(x);
					 break;
			case 3 : printf("\n Enter value after which u want to insert :");
					 scanf("%d",&a);
					 printf("\n Enter value to insert  :");
					 scanf("%d",&x);
					 InsertAfterAGivenNode(a,x);
					 	break;
			case 4 : Delete1stNode();
					 	break;
			case 5 : Deletelastnode();
						break;
			case 6 : printf("\n Enter the position u want to delete :");
					 scanf("%d",&x);
					 delete_ith( x);
					 break;
			case 7 : ForwardDisplay();
						break;
			case 8 : BackwardDisplay(head);
						break;
			case 9 : Reverselist();
						break;
			case 10 :  printf("\n\n\n\t\tEnter the element you want to search : ");
				  scanf("%d", &x);
				  fflush(stdin);
				  ptr = SearchElement(x);
				  if(ptr != NULL)
					printf("\n\n\n\n\t\tElement exists in the list.");
				  else
					printf("\n\n\n\n\t\tThis element does not exist in the list.");
				  getch();
					break;
			case 0 : exit(0);

			default: printf("\n\tInvalid choice.");
		}
		getch();
	}
}
