#include<stdio.h>
#include<malloc.h>
#define MAX 10
struct node{
	int info;
	struct node *link;
};
struct node *getnode();
void addfirst(struct node **,int );
void append(struct node **,int );
void addafter(struct node **,int ,int );
void search(struct node *,int ,struct node ** ,struct node ** );
void delnode(struct node **,int );
void traverse(struct node *);
int counter(struct node *);
void freeall(struct node **);
void reverse(struct node **);

struct node *getnode()
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	return t;
}
void addfirst(struct node **start,int item)
{
	struct node *new;
	new=getnode();
	if(new==NULL)
	{
		printf("overflow");
		return;
	}
	new->info=item;
	new->link=*start;
	*start=new;
}
void append(struct node **start,int item)
{
	struct node *new,*ptr;
	new=getnode();
	if(new==NULL)
	{
		printf("overflow");
		return;
	}
	new->info=item;
	new->link=NULL;
	if(*start==NULL)
		*start=new;
	else
	{
		ptr=*start;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=new;
	}
}
void addafter(struct node **start,int item,int pos)
{
	struct node *new,*ptr;
	int i;
	for(ptr=*start,i=1;i<pos;i++,ptr=ptr->link)
	{
		if(ptr==NULL)
		{
			printf("no such node");
			return;
		}
	}
	new=getnode();
	if(new==NULL)
	{
		printf("overflow");
		return;
	}
	new->info=item;
	new->link=ptr->link;
	ptr->link=new;
}
void traverse(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->link;
	}
}
int counter(struct node *start)
{
	struct node *ptr;
	int cnt=0;
	ptr=start;
	while(ptr!=NULL)
	{
		cnt++;
		ptr=ptr->link;
	}
	return cnt;
}
void freeall(struct node **start)
{
	struct node *ptr;
	while(*start!=NULL)
	{
		ptr=*start;
		*start=(*start)->link;
		free(ptr);
	}
}
void search(struct node *start,int item,struct node **loc,struct node **locp)
{
	*locp=NULL;
	*loc=start;
	while(*loc!=NULL&&(*loc)->info!=item)
	{
		*locp=*loc;
		*loc=(*loc)->link;
	}
}
void delnode(struct node **start,int item)
{
	struct node *loc,*locp;
	search(*start,item,&loc,&locp);
	if(loc==NULL)
		printf("item not found");
	else if(locp==NULL)
		*start=(*start)->link;
	else
		locp->link=loc->link;
	free(loc);
}
void reverse(struct node **start)
{
	struct node *p1,*p2,*p3;
	p1=*start;
	p2=NULL;
	while(p1!=NULL)
	{
		p3=p2;
		p2=p1;
		p1=p1->link;
		p2->link=p3;
	}
	*start=p2;
}
