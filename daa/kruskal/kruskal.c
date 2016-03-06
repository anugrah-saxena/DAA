// weight = 1000 denotes infinite distance
// u=1 & v=2
#include<stdio.h>
#include<stdlib.h>

int **a;
int **w;
int **spantree;		//spanning tree will have the final set of edges to be included... initially NULL set
int **sort;
//int *prev;
//int *next;
int *makeset;
FILE *fp;
FILE *wt;
int main()
{
	int i,j,l=0,n,k=0,min,edges=0;
	int tempw,tempi,tempj;
	int spanvertex=0;
	int totalwt=0;
	char temp[10];

	fp=fopen("inputkruskal.txt","r");
	fscanf(fp,"%s",temp);
	n=atoi(temp);

	wt=fopen("weightkruskal.txt","r");

	a=(int **)(malloc(n*sizeof(int *)));
	for(i=0;i<n;i++)
		a[i]=(int *)(malloc(n*sizeof(int)));

	w=(int **)(malloc(n*sizeof(int *)));
	for(i=0;i<n;i++)
		w[i]=(int *)(malloc(n*sizeof(int)));

	makeset=(int *)(malloc(n*sizeof(int)));
//	prev=(int *)(malloc(n*sizeof(int)));
//	next=(int *)(malloc(n*sizeof(int)));

	for(i=0;i<n;i++)
	{
		//makeset
		makeset[i]=i;
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%s",temp);
			a[i][j]=atoi(temp);
			fscanf(wt,"%s",temp);
			w[i][j]=atoi(temp);
			if(a[i][j]!=0)
				edges++;
		}
	}

	fclose(fp);	fclose(wt);
	
	fp=fopen("outputkruskal.txt","w");


//printf("\n%d\n",w[0][1]);
//	edges=edges/2;

	sort=(int **)(malloc(edges*sizeof(int *)));
	for(i=0;i<edges;i++)
		sort[i]=(int *)(malloc(3*sizeof(int)));


	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(w[i][j]==0||w[i][j]==1000)
			continue;

			k=0;
			sort[l][k++]=w[i][j];
			sort[l][k++]=i;
			sort[l][k++]=j;
//			printf("\n l= %d k=%d i= %d j=%d edges= %d sort= %d",l,k,i,j,edges,sort[l][0]);
			l++;
		}		

//	for(i=0;i<n;)


	//sort edges in E by insertion sort
//	printf("%d",edges);
//	heapsort(sort,edges);
	for(i=1;i<edges;i++)
	{
		tempw=sort[i][0];
		tempi=sort[i][1];
		tempj=sort[i][2];
		for(j=i-1;j>=0&&sort[j][0]>tempw;j--)
		{
//			printf("i=%d j=%d sortw=%d sorti=%d sortj=%d\n",i,j,sort[j][0],sort[j][1],sort[j][2]);
			sort[j+1][0]=sort[j][0];
			sort[j+1][1]=sort[j][1];
			sort[j+1][2]=sort[j][2];
//			printf("\ni= %d j=%d edges= %d sort= %d",i,j,edges,sort[l][0]);
		}
		sort[j+1][0]=tempw;
		sort[j+1][1]=tempi;
		sort[j+1][2]=tempj;
	}
	//end of insertion sort

//check sort array
//	for(i=0;i<edges;i++)
//		printf("sortw=%d sorti=%d sortj=%d\n",sort[i][0],sort[i][1],sort[i][2]);

//Edge in sorted order tracing and finding set

	spantree=(int **)(malloc(edges*sizeof(int *)));
	for(i=0;i<edges;i++)
		spantree[i]=(int *)(malloc(3*sizeof(int)));

//	for(i=0;i<n;i++)
//		printf("%d\n",makeset[i]);

// start of findset and union function
	for(i=0;i<edges;i++)
	{
		if(makeset[sort[i][1]]!=makeset[sort[i][2]])
		{
//intermediate check before updation
//		printf("0	mi %d=%d mj %d=%d\n",sort[i][1],makeset[sort[i][1]],sort[i][2],makeset[sort[i][2]]);
//for(j=0;j<n;j++)
//	printf("%d\t",makeset[j]);
//printf("\n");
			spantree[i][0]=sort[i][0];
			spantree[i][1]=sort[i][1];
			spantree[i][2]=sort[i][2];
			spanvertex++;
		fprintf(fp,"Edge %d - %d (with weight %d) is included\n",spantree[i][1],spantree[i][2],spantree[i][0]);
			totalwt+=spantree[i][0];
			// update sub-set with findset[u]=findset[v]
			if(makeset[sort[i][1]]<makeset[sort[i][2]])
			{
				for(j=0;j<n;j++)
				{
					if(j==sort[i][2])
						continue;
					if(makeset[j]==makeset[sort[i][2]])
						makeset[j]=makeset[sort[i][1]];
				}
			makeset[sort[i][2]]=makeset[sort[i][1]];
			}
			else
			{
				for(j=0;j<n;j++)
				{
					if(j==sort[i][1])
						continue;
					if(makeset[j]==makeset[sort[i][1]])
						makeset[j]=makeset[sort[i][2]];
				}
			makeset[sort[i][1]]=makeset[sort[i][2]];
			}

//intermediate check after updation
//		printf("1	mi %d=%d mj %d=%d\n",sort[i][1],makeset[sort[i][1]],sort[i][2],makeset[sort[i][2]]);
//for(j=0;j<n;j++)
//	printf("%d\t",makeset[j]);
//printf("\n");
		}
	}

// finish of findset and union function print result in output.txt

	fprintf(fp,"\nTotal minimum spanning tree weight is = %d\n",totalwt);


	fclose(fp);

	free(a);	free(w);	free(makeset);		free(sort);	free(spantree);	//free(prev);	//free(next);
return 0;
}
