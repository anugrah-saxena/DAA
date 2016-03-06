#include "stk.h"
void main()
{
	int ch,item;
	struct stack s1;
	s1.top=-1;
	do{
		printf("\n------main menu------\n");
		printf("1. push to stack\n2. pop from stack\n3. top value of stack\n4. exit\npress:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nenter value to push");
				scanf("%d",&item);
				push(&s1,item);
				break;
			case 2:
				item=pop(&s1);
				printf("\npopped value is %d",item);
				break;
			case 3:
				item=topval(s1);
				printf("\ntop value is %d",item);
				break;
			case 4:
				break;
			default:
				printf("\nincorrect entry");
		}
	}while(ch!=4);
}

