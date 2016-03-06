#include "link.h"
void main()
{
	int ch,item,pos,cnt;
	struct node *p;
	p=NULL;
	do{
		printf("\n------main menu------\n");
		printf("1. addfirst\n2. append\n3. addafter\n4. delete\n5. traverse\n6. count\n7. reverse\n8. exit\npress:");
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
				reverse(&p);
				break;
			case 8:
				freeall(&p);
				break;
			default:
				printf("\nincorrect entry");
		}
	}while(ch!=8);
}
