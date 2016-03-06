#include "que.h"
#include "stk.h"
void rev(struct stack *,struct stack *);
void rev2(struct stack *,struct stack *);
void main()
{
	int ch,item;
	struct stack q1;
	q1.top=-1;
	struct stack q2;
	q2.top=-1;

	do{
		printf("\n------main menu------\n");
		printf("1. push to queue\n2. pop from queue\n3. exit\npress:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nenter value to push");
				scanf("%d",&item);
				push(&q1,item);
				break;
			case 2:
				rev(&q1,&q2);
				item=pop(&q2);
				if(item!=-10)
				{
					printf("\npopped value is %d",item);
					rev2(&q1,&q2);
				}
				else
					printf("\nempty queue");
				break;
			case 3:
				break;
			default:
				printf("\nincorrect entry");
		}
	}while(ch!=3);
}
void rev(struct stack *q1,struct stack *q2)
{
	q2->top++;
	while(q1->top!=-1)
	{
//	printf("\t%d\t%d\t",q2->top,q1->top);
		q2->data[++q2->top]=q1->data[q1->top--];
	}
}
void rev2(struct stack *q1,struct stack *q2)
{
//	q1->top++;
	while(q2->top!=-1)
	{
//	printf("\t%d\t%d\t",q2->top,q1->top);
		q1->data[++q1->top]=q2->data[q2->top--];
	}
}
