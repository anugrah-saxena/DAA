#include<stdio.h>
#include "que.h"
int main()
{
	int i,j,n,item,count=0;
	printf("enter no. of nodes");
	scanf("%d",&n);
	int a[n][n];
	int color[n];

//	int out[n];

	for(i=0;i<n;i++)
	{
		color[i]=-1;
	}
	printf("enter adjacency matrix\n");

	for(i=0;i<n;i++)
	{
		printf("\nenter adjacency matrix value for node %d\n",i);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nmatrix\n");
	for(i=0;i<n;i++)
		printf("\t%d",i);
	for(i=0;i<n;i++)
	{
		printf("\n%d\t",i);
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
	}
	printf("\nenter starting node");
	scanf("%d",&item);

//printf("hello");

	struct queue q1;
	q1.front=-1;
	q1.rear=-1;
	addq(&q1,item);
	color[item]=0;

//printf("hello");

	while(1)
	{
		item=delq(&q1);
		printf("%d(%d)->",item,count);

		if(item==-10)
		{
			printf("NULL");
			break;
		}
		for(i=0;i<n;i++)
		{

			if(a[item][i]==1&&color[i]==-1)
			{
				addq(&q1,i);
				color[i]=0;
			}
		}
//			out[count]=item;
			color[item]=1;

			count++;
		
	}	
//	for(i=0;i<n;i++)
//		printf("%d,%d->",out[i],i);
return 0;
}
