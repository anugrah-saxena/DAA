// wt infinite = -1
#include<stdio.h>
#include<stdlib.h>
#include "que.h"

int **w;
int **s;
int *parent;
int *distance;
//int *q;
FILE *fp;
int main()
{
	int i,j,n,source,u,v,tempo;
	char temp[10];
	fp=fopen("input.txt","r");
	fscanf(fp,"%s",temp);
	n=atoi(temp);
	fscanf(fp,"%s",temp);
	source=atoi(temp);

	struct queue q1;
	q1.front=-1;
	q1.rear=-1;

	w=(int **)(malloc(n*sizeof(int *)));
	for(i=0;i<n;i++)
		w[i]=(int *)(malloc(n*sizeof(int)));

	s=(int **)(malloc(n*sizeof(int *)));
	for(i=0;i<n;i++)
		s[i]=(int *)(malloc(1*sizeof(int)));

	parent=(int *)(malloc(n*sizeof(int)));
	distance=(int *)(malloc(n*sizeof(int)));
//	q=(int *)(malloc(n*sizeof(int)));

	for(i=0;i<n;i++)
	{
		distance[i]=1000;
//		parent[i]=-1;
		s[i][0]=0;
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%s",temp);
			w[i][j]=atoi(temp);
		}
	}
fclose(fp);

fp=fopen("output.txt","w");
	distance[source]=0;
	parent[source]=-1;

	addq(&q1,source);

//	for(i=0;i<n;i++)
//		printf("node=%d parent=%d distance=%d si0=%d\n",i,parent[i],distance[i],s[1][0]);


	while(1)
	{
		u=delq(&q1);

		if(u==-10)
		{
			printf("NULL\n");
			break;
		}
		else
		{
			s[u][0]=1;
			for(i=0;i<n;i++)
			{
				// Relax function
				if(w[u][i]!=-1)
				{
				v=i;
					if(distance[v]>distance[u]+w[u][v])
					{
						distance[v]=distance[u]+w[u][v];
						parent[v]=u;
					}
				}
			}
		}

		u=-10;
		for(i=0;i<n;i++)
		{
		tempo=1000;
			if((s[i][0]==0)&&(distance[i]<tempo))
			{
				tempo=distance[i];
				u=i;
			}
		}
		addq(&q1,u);
	}

	for(i=0;i<n;i++)
		fprintf(fp,"node=%d parent=%d distance=%d\n",i,parent[i],distance[i]);


	free(w);	free(parent);		free(distance);		/*free(q);*/	free(s);

	fclose(fp);
return 0;
}
