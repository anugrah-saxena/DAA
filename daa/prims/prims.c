// let -1 be NIL and 1000 Infinite
#include<stdio.h>
#include<stdlib.h>
#include "que.h"

int **a;
int **w;
int *parent;
int *key;
int **q;
FILE *fp;
FILE *wt;
int main()
{
	int i,j,k,n,item,root;
	char temp[10];

	struct queue q1;
	q1.front=-1;
	q1.rear=-1;

	fp=fopen("inputprim.txt","r");

	fscanf(fp,"%s",temp);
	n=atoi(temp);

	wt=fopen("weightprim.txt","r");

	fscanf(wt,"%s",temp);
	root=atoi(temp);

	q=(int **)(malloc(n*sizeof(int *)));
	for(i=0;i<n;i++)
		q[i]=(int *)(malloc(2*sizeof(int)));


	for(i=0;i<n;i++)
	{
		fscanf(wt,"%s",temp);
		item=atoi(temp);
		addq(&q1,item);
		q[i][0]=item;
		q[i][1]=1;
//	printf("%d=qitem=%d qp=%d\n",item,q[i][0],q[i][1]);
	}

	for(i=0;i<n;i++)
		printf("%d=qitem=%d qp=%d\n",i,q[i][0],q[i][1]);

	a=(int **)(malloc(n*sizeof(int *)));
	for(i=0;i<n;i++)
		a[i]=(int *)(malloc(n*sizeof(int)));

	w=(int **)(malloc(n*sizeof(int *)));
	for(i=0;i<n;i++)
		w[i]=(int *)(malloc(n*sizeof(int)));

	parent=(int *)(malloc(n*sizeof(int)));
	key=(int *)(malloc(n*sizeof(int)));

	for(i=0;i<n;i++)
	{
		key[i]=1000;
		parent[i]=-1;
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%s",temp);
			a[i][j]=atoi(temp);
			fscanf(wt,"%s",temp);
			w[i][j]=atoi(temp);
		}
	}
	key[root]=0;

	fclose(fp);	fclose(wt);

	fp=fopen("outputprim.txt","w");

// u = item and v = i
	while(1)
	{
		item=delq(&q1);

		if(item==-10)
		{
			printf("NULL\n");
			break;
		}
		else
		{
		// dequeue and removing flag
			for(k=0;k<n;k++)
			{
//fprintf(fp,"0	v=%d p=%d k=%d & %d - %d & %d\n",k,parent[k],key[k],q[k][0],item,q[k][1]);
				if(q[k][0]==item)
					q[k][1]=0;
//fprintf(fp,"01	v=%d p=%d k=%d & %d - %d & %d\n",k,parent[k],key[k],q[k][0],item,q[k][1]);
			}


	// adjacency checking
			for(i=0;i<n;i++)
			{
//fprintf(fp,"1	v=%d p=%d k=%d & %d - %d & %d\n",i,parent[i],key[i],q[i][0],item,q[i][1]);
				if((a[item][i]==1)&&(w[item][i]<key[i]))
				{
					parent[i]=item;
					key[i]=w[item][i];
//fprintf(fp,"11	v=%d p=%d k=%d & %d - %d & %d\n",i,parent[i],key[i],q[i][0],item,q[i][1]);
				}
			}			
		}
	}

	for(i=0;i<n;i++)
		fprintf(fp,"node=%d parent=%d key=%d & %d & %d\n",i,parent[i],key[i],q[i][0],q[i][1]);


	fclose(fp);
	free(a);	free(w);	free(parent);	free(key);	free(q);
return 0;
}
