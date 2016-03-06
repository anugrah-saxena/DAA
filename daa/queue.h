#include<malloc.h>
#include<stdlib.h>
int tempval;
typedef struct node
{
	int val;
	struct node *next;
}node;

typedef struct queue
{
	node *front,*rear;
}queue;

void traverse( queue *head)
{
	node *p;
	p=head->front;	
	if(p==NULL)
		printf("Queue is Empty\n");
	else	
	{
		while(p!=NULL)
		{
			printf("%d ",p->val);
			p=p->next;
		}
	printf("\n");
	}
}

queue *insert(queue *head,int data)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->val=data;
	temp->next=NULL;
	if(head->front==NULL)
	{
		head->front=head->rear=temp;
	}
	else
	{
		head->rear->next=temp;
		head->rear=head->rear->next;
	}
	return head;
}

queue *del(queue *head)
{
	node *p;
	if(head->front==NULL)
		printf("Queue is empty\n");
	else
	{
		p=head->front;
		tempval=p->val;
		head->front=head->front->next;
		free(p);
	}
	return head;
}

void queue_ds()
{
	int i,j;
	queue *head;
	head=(queue *)malloc(sizeof(queue));
	head->front=NULL;
	head->rear=NULL;
	while(1)
	{
		printf("1. Insert an element\n2. Delete an element\n3. Traverse the Queue\n4. Exit\nEnter your choice: ");
		scanf("%d",&i);
		switch(i)
		{
			case 1:	printf("Enter the value to Insert: ");
					scanf("%d",&j);
					head=insert(head,j);
					break;
			case 2:	head=del(head);
					break;
			case 3:	traverse(head);
					break;
			case 4:	exit(0);	
			default:	printf("Wrong choice\n");
		}
	}
}



