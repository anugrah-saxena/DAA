#include<stdio.h>
#define MAX 10
struct stack{
	int data[MAX];
	int top;
};
void push(struct stack *,int );
int pop(struct stack *);
int topval(struct stack);

void push(struct stack *s,int item)
{
	if(s->top==MAX-1)
	{
		printf("\nstack overflow");
		return;
	}
	s->top++;
	s->data[s->top]=item;
}
int pop(struct stack *s)
{
	int item;
	if(s->top==-1)
	{
		printf("\nstack underflow");
		return NULL;
	}
	item=s->data[s->top--];
	return item;
}
int topval(struct stack s)
{
	int item;
	if(s.top==-1)
	{
		printf("stack underflow");
		return NULL;
	}
	item=s.data[s.top];
	return item;
}
