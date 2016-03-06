#include<stdio.h>
#include<stdlib.h>
#include "link.h"
void dfs_visit(int , int , int , int **, int *, int *, int *, int *);

int count;
int *dfsno;
int *lowval;
int *lowchild;
int *child;
struct node *p;
FILE *fp;
int k;

int main()
{
	int i,j,x,n,item,rootchild=0;
	count=0;
	k=1;
	p=NULL;
//

	char temp[10];

	fp=fopen("input2.txt","r");
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

	dfsno=(int *)(malloc(n*sizeof(int)));
	lowval=(int *)(malloc(n*sizeof(int)));
	lowchild=(int *)(malloc(n*sizeof(int)));
	child=(int *)(malloc(n*sizeof(int)));

	fprintf(fp,"------adjacency matrix------\n");

	for(i=0;i<n;i++)
	{
		// initially color is white and parent is null.
		color[i]=-1;
		parent[i]=-1;
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%s",temp);
			a[i][j]=atoi(temp);
		}
	// lets give low_value of child as n
	lowchild[i]=n;
	}

	fclose(fp);

	fp=fopen("output2.txt","w");

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

	// defining no of childs for each node
	for(i=1;i<n;i++)
	{
		if(parent[i]==0)
			rootchild++;
	}
	child[0]=rootchild;
	for(i=1;i<n;i++)
	{
		x=0;
		for(j=1;j<n;j++)
		{
			if(parent[j]==i)
				x++;
		}
		child[i]=x;
	}

	for(i=0;i<n;i++)
	{
		if(child[i]==0)
			lowchild[i]=-1;
	}

	// check point for dfsno. and initial low_value.
	for(i=0;i<n;i++)
		fprintf(fp,"\ndfsno & low_value of node %d = %d & %d",i,dfsno[i],lowval[i]);
	fprintf(fp,"\n");


	// backedge and update lowval & lowchild
	for(i=n-1;i>=0;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			// backedge.
			if((a[i][j]==1)&&(parent[i]!=j))
			{
				lowval[i]=dfsno[j];
			}
		}
	}

/*	for(i=n-1;i>0;i--)
	{
		if(lowval[i]<lowval[parent[i]])
//			fprintf(fp,"hello\n");
			lowval[parent[i]]=lowval[i];
	}
*/
	for(i=n-1;i>=0;i--)
	{
		for(x=i+1;x<n;x++)
		{
			if((a[i][x]==1)&&(parent[x]==i))
			{
				if(lowval[x]<lowchild[i])
					lowchild[i]=lowval[x];
			}
		}
	}

	// check point for updated low_value & lowest low_value of child nodes.
	for(i=0;i<n;i++)
		fprintf(fp,"\ndfsno & updated low_value and lowchild of node %d = %d & %d & %d",i,dfsno[i],lowval[i],lowchild[i]);
	fprintf(fp,"\n");

	// final updation by taking minimum of node's dfsno||lowval(---backedges---)||lowchild(---child nodes---)
	for(i=n-1;i>=0;i--)
	{
		if(lowval[i]>lowchild[i]&&lowchild[i]!=-1)
			lowval[i]=lowchild[i];
		if(lowval[i]>dfsno[i])
			lowval[i]=dfsno[i];
	}

	// check point for re-updated low_value & lowest low_value of child nodes.
	for(i=0;i<n;i++)
		fprintf(fp,"\ndfsno & updated low_value and lowchild of node %d = %d & %d & %d",i,dfsno[i],lowval[i],lowchild[i]);
	fprintf(fp,"\n");

	// selection of articulation points

	fprintf(fp,"\n\narticulation points are:\n");

	for(i=n-1;i>=0;i--)
	{
		if(lowval[i]>=dfsno[parent[i]]&&parent[i]!=-1)
		{
			if((parent[i]==0)&&(rootchild<2))
				continue;
			fprintf(fp,"node = %d, dfsno = %d, low_value = %d\t",parent[i],dfsno[parent[i]],lowval[parent[i]]);
		}
	}


	fclose(fp);
free(dfsno); free(lowval); free(a); free(color); free(parent); free(d); free(f); free(child);
return 0;
}
void dfs_visit(int i, int j, int n, int **a, int *color, int *parent, int *d, int *f)
{
		color[i]=0;
		count++;
		d[i]=count;
		// initializing low_value and dfsno as the node is discovered.
		lowval[i]=k;
		dfsno[i]=k++;
//		lowchild[i]=dfsno[i];

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
		// adding node to the start of the linklist as soon as it and its sub-tree is traversed. i.e., node becomes black.
		addfirst(&p,i);
		fprintf(fp,"\t%d(%d,%d,%d)",i,d[i],f[i],parent[i]);
}
