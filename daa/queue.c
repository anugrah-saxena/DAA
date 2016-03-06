#include "que.h"
void main()
{
	int ch,item;
	struct queue q1;
	q1.front=q1.rear=-1;
	do{
		printf("\n------main menu------\n");
		printf("1. add to queue\n2. delete from queue\n3. exit\npress:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nenter value to add");
				scanf("%d",&item);
				addq(&q1,item);
				break;
			case 2:
				item=delq(&q1);
				if(item!=-10)
					printf("\ndeleted value is %d",item);
				break;
			case 3:
				break;
			default:
				printf("\nincorrect entry");
		}
	}while(ch!=3);
}

