#include<stdio.h>
#include<malloc.h>
#include<conio.h> 
#include<stdlib.h> 
struct node
{
	int data;
	struct node *next, *prev;
};
typedef struct node ND;
ND *head=NULL;

void insert_beg(int x)
{
	ND *temp;
	temp=(ND*)malloc(sizeof(ND));
	temp->data=x;
	if(head==NULL)
		{
			temp->next=NULL;
			temp->prev=NULL;
			head=temp;
		}
	else
		{
			temp->prev=NULL;
			temp->next=head;
			head->prev=temp;
			head=temp;
		}
}

void insert_end(int x)
{
	ND *temp, *curr;
	temp=(ND*)malloc(sizeof(ND));
	temp->data=x;
	if(head==NULL)
	{
		temp->next=NULL;
		temp->prev=NULL;
		head=temp;
	}
	else
	{
		curr=head;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=temp;
		temp->next=NULL;
		temp->prev=curr;
	}
}

void delete_first()
{
	ND *ptr;
	if(head==NULL)
	{
		printf("\nEmpty List");
		getch();
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nFirst node is deleted!");
		getch();
	}
	else
	{
		ptr=head;
		head=head->next;
		head->prev=NULL;
		free(ptr);
		printf("\nFirst node is deleted!");
		getch();
	}
}

void delete_last()
{
	ND *ptr;
	if(head==NULL)
	{
		printf("\nEmpty List");
		getch();
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nLast node is deleted!");
		getch();
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->prev->next=NULL;
		free(ptr);
		printf("\nLast node is deleted!");
		getch();
	}
}
void display()
{
	ND *p;
	p=head;
    while(p!=NULL)
      {
		printf("%d <==> ",p->data);
		p=p->next;
      }
    getch();
}

void main()
{
	do{
	int ch,x;
		system("cls");
	printf("\n1.Insert beginning \n2.Insert ending \n3.Delete beginning \n4.Delete Ending \n5.Display \n0.Exit");
	printf("\nEnter your choice:");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:printf("\nEnter the value to insert at beginning: ");
			   scanf("%d",&x);
			   insert_beg(x);
			   break;
		case 2:printf("\nEnter the value to insert at end: ");
			   scanf("%d",&x);
			   insert_end(x);
			   break;
		case 3:delete_first();
			   break;
		case 4:delete_last();
			   break;
		case 5: display();
				break;
		case 0: exit(0);
	}
	}while(1);
}
