#include<stdio.h>
#include<conio.h>

struct Queue
 {
   int data;
   struct node *next;
 };
 typedef struct Queue QU;
QU *rear=NULL;
QU *front=NULL;

 void insert(int x)
   {
     QU *temp;
     temp=(ND*)malloc(sizeof(ND));
     if(!temp)
       {
	  printf("\n Overflow");
	  return;
       }
     temp->data=x;
     temp->next=NULL;
     if(rear==NULL && front ==NULL)
       {
	  rear=temp;
	  front=temp;
       }
     else
       {
	  rear->next=temp;
	  rear=temp;
       }
   }

 void delete_q()
  {
    QU *p;
    if(front==NULL)
      {
	printf("\n Underflow");
	getch();
      }
    else
      {
	p=front;
	front=front->next;
	printf("\n Deleted element is %d",p->data);
	free(p);
	getch();
      }
  }



void main()
  {
    int ch,x;
    do
      {
	clrscr();
	printf("\n 1. INSERT");
	printf("\n 2. DELETE");
	printf("\n 0. Exit");
	printf("\n Enter your choice");
	scanf("%d",&ch);
	switch(ch)
	  {
	     case 1: printf("\n Enter value to insert");
		     scanf("%d",&x);
		     insert(x);
		     break;
	     case 2: delete_q();
		     break;

	     case 0: exit(0);
	   }
	 }while(1);
      }