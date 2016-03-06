#include<stdio.h>
#include<malloc.h>
#define MAX 10
struct node{
	int info;
	struct node *l;
	struct node *r;
};
struct node *getnode();
void addfirst(struct node **,int );
void append(struct node **,int );
void addafter(struct node **,int ,int );
void search(struct node *,int ,struct node ** ,struct node ** );
void delnode(struct node **,int );
void traverse(struct node *);
int count(struct node *);
void freeall(struct node **);
void reverse(struct node **);
void main()
{
	int ch,item,pos,cnt;
	struct node *p;
	p->l=NULL;
	p->r=NULL;
	do{
		printf("\n------main menu------\n");
		printf("1. addfirst\n2. append\n3. addafter\n4. delete\n5. traverse\n6. count\n7. exit\npress:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nenter value");
				scanf("%d",&item);
				addfirst(&p,item);
				break;
			case 2:
				printf("\nenter value");
				scanf("%d",&item);
				append(&p,item);
				break;
			case 3:
				printf("\nenter value and position");
				scanf("%d%d",&item,&pos);
				addafter(&p,item,pos);
				break;
			case 4:
				printf("\nenter item to delete");
				scanf("%d",&item);
				delnode(&p,item);
				break;
			case 5:
				traverse(p);
				break;
			case 6:
				cnt=count(p);
				printf("%d",cnt);
				break;
			case 7:
				freeall(&p);
				break;
			default:
				printf("\nincorrect entry");
		}
	}while(ch!=7);
}
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
	new->l=NULL;
	new->r=start->l;
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
	new->l=NULL;
	new->r=NULL;
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
int count(struct node *start)
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
	struct node *ptr,*ptr2;
	ptr=*start;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	// ptr now at last node and ptr2 at start
	ptr2=*start;
	while(ptr2->link!=ptr->link)
	
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
