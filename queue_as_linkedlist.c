#include<stdio.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node  *m;
struct node *n = NULL;
struct node *o = NULL;
int count=0;
void enq(int );
void deq();
void display();

void main ()
{
	int choice,x;
	do{
		printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.QUIT\nEnter your x=");
		scanf("%x",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter=");
				scanf("%x",&x);
				enq(x);
				break;
			case 2:
				deq();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("Invalid Input\n");
		}
		}while(choice!=4);
}

void enq(int choice)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if (o==NULL)
	{
		o=temp;
		n=temp;
		o->data=choice;
		o->prev=NULL;
		o->next=NULL;
		m=temp;
		
		
	}
	else
	{
		m->next=temp;
		temp->data=choice;
		temp->prev=m;
		temp->next=NULL;
		m=temp;
	}
}

void deq()
{
	struct node *choice;
	int y;
	if (n==NULL)
	{
		printf("EMPTY QUEUE\n");
		return;
	}
	else
	{
		y=n->data;
		choice=n->next;
		printf("Dequeued Element=%x\n",y);
		free(n);
		n=choice;
	}
}

void display() {
   struct node *temp;
   
   temp = n;
   
   if (n==NULL) {
      printf("EMPTY QUEUE\n");
      return;
   }
   
   while (temp->next != NULL) {
      printf("%x  ", temp->data);
      temp = temp->next;
   }
   printf("%x\n", temp->data);
}