#include<stdio.h>
#define MAX 10
struct queue{
	int data[MAX];
	int front,rear;
};
void addq(struct queue *,int );
int delq(struct queue *);

void addq(struct queue *q,int item)
{
	if(q->rear==MAX-1)
	{
		printf("\nqueue is full");
		return;
	}
	if(q->front==-1)
		q->front=q->rear=0;
	else
		q->rear++;
	q->data[q->rear]=item;
}
int delq(struct queue *q)
{
	int item;
	if(q->front==-1)
	{
//		printf("\nqueue is empty");
		return -10;
	}
	item=q->data[q->front];
	if(q->front==q->rear)
		q->front=q->rear=-1;
	else
		q->front++;
	return item;
}
