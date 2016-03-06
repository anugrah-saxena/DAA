#include<stdio.h>
#include<malloc.h>
struct stack{
	int info;
	struct stack *link;
};
void push(struct stack **,int );
int pop(struct stack **);
int topval(struct stack *);
struct stack *getnode();

void push(struct stack **top,int item)
{
	struct stack *new;
	new=getnode();
	if(new==NULL)
	{
		printf("\nstack overflow");
		return;
	}
	new->info=item;
	new->link=*top;
	*top=new;
}
int pop(struct stack **top)
{
	struct stack *ptr;
	int item;
	if(*top==NULL)
	{
		printf("\nstack underflow");
		return NULL;
	}
	ptr=*top;
	*top=(*top)->link;
	item=ptr->info;
//	free(ptr);
	return item;
}
int topval(struct stack *top)
{
	int item;
	if(top==NULL)
	{
		printf("stack underflow");
		return NULL;
	}
	item=top->info;
	return item;
}
struct stack *getnode()
{
	struct stack *t;
	t=(struct stack*)malloc(sizeof(struct stack));
	return t;
}
