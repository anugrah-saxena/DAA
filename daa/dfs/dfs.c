#include<stdio.h>
#include<stdlib.h>
#include "link.h"
void dfs_visit(int , int , int , int **, int *, int *, int *, int *);

int count;
struct node *p;
FILE *fp;

int main()
{
	int i,j,n,item;
	count=0;
	p=NULL;


	char temp[10];

	fp=fopen("input.txt","r");
	fscanf(fp,"%s",temp);
	n=atoi(temp);

//	int a[n][n];
	int **a;
	a=(int **)(malloc(n*sizeof(int *)));
	for(i=0;i<n;i++)
		a[i]=(int *)(malloc(n*sizeof(int)));

	int *color;
	int *parent;
	int *d,*f;

	color=(int *)(malloc(n*sizeof(int)));
	parent=(int *)(malloc(n*sizeof(int)));
	d=(int *)(malloc(n*sizeof(int)));
	f=(int *)(malloc(n*sizeof(int)));

	fprintf(fp,"------adjacency matrix------\n");

	for(i=0;i<n;i++)
	{
		color[i]=-1;
		parent[i]=-1;
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%s",temp);
			a[i][j]=atoi(temp);
		}
	}

	fclose(fp);

	fp=fopen("output.txt","w");

//	printf("\nmatrix\n");
	for(i=0;i<n;i++)
		fprintf(fp,"\t%d",i);
	fprintf(fp,"\n");
	for(i=0;i<n;i++)
		fprintf(fp,"---------");

	for(i=0;i<n;i++)
	{
		fprintf(fp,"\n%d|\t",i);
		for(j=0;j<n;j++)
		{
			fprintf(fp,"%d\t",a[i][j]);
		}
	}
	fprintf(fp,"\n");

	fprintf(fp,"\n------dfs traversal------\n");

	for(i=0;i<n;i++)
	{
		if(color[i]==-1)
		{
			//then DFS_visit(u)
			dfs_visit(i,j,n,a,color,parent,d,f);
		}
	}

	fprintf(fp,"\n");

	printf("\n------traversal order------\n");
	traverse(p);
	printf("\n");

	fclose(fp);
free(color); free(parent); free(d); free(f); free(a);
return 0;
}
void dfs_visit(int i, int j, int n, int **a, int *color, int *parent, int *d, int *f)
{
		color[i]=0;
		count++;
		d[i]=count;

		for(j=0;j<n;j++)
		{
			if(a[i][j]==1&&color[j]==-1)
			{
				parent[j]=i;
				dfs_visit(j,0,n,a,color,parent,d,f);
			}
		}
		color[i]=1;
		count++;
		f[i]=count;
		addfirst(&p,i);
		fprintf(fp,"\t%d(%d,%d,%d)",i,d[i],f[i],parent[i]);
}
