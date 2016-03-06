// wt infinite = 1000
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int **w;
//int *s;
int *parent;
int *distance;
FILE *fp;
int main()
{
	int temp1[10];
	int i,j,n,source=0,u,v,tempo,count=0;
	char temp[10];
	fp=fopen("input.txt","r");
//	fscanf(fp,"%s",temp);
//	n=atoi(temp);
//	fscanf(fp,"%s",temp);
//	source=atoi(temp);

	do
	{
		count++;
//	printf("%d\n",count);
	}while((fscanf(fp,"%d",temp1))!=EOF);
	n=sqrt(count);

	printf("%d",n);


	w=(int **)(malloc(n*sizeof(int *)));
	for(i=0;i<n;i++)
		w[i]=(int *)(malloc(n*sizeof(int)));

//	s=(int *)(malloc(1*sizeof(int)));

	parent=(int *)(malloc(n*sizeof(int)));
	distance=(int *)(malloc(n*sizeof(int)));

	// count n
rewind(fp);

	for(i=0;i<n;i++)
	{
		distance[i]=1000;
//		parent[i]=-1;
//		s[i]=0;
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%s",temp);
			w[i][j]=atoi(temp);
		}
	}

// initialize for source vertex
	distance[source]=0;
	parent[source]=-1;

fclose(fp);

fp=fopen("output.txt","w");


	// relax function
	for(j=n-2;j>=0;j--)
		for(u=0;u<n;u++)
			for(i=0;i<n;i++)
			{
				// Relax function
				if(w[u][i]!=1000)
				{
				v=i;
					if(distance[v]>distance[u]+w[u][v])
					{
						distance[v]=distance[u]+w[u][v];
						parent[v]=u;
					}
				}
			}


			// negative cycle
			for(u=0;u<n;u++)
				for(v=0;v<n;v++)
				{
					if(distance[v]>distance[u]+w[u][v])
					{
						printf("negative cycle\n");
						exit(1);
					}
				}


			// print final graph
			for(i=0;i<n;i++)
				fprintf(fp,"vertex = %d distance = %d parent = %d\n",i,distance[i],parent[i]);


	free(w);	free(parent);		free(distance);		//free(s);

	fclose(fp);
return 0;
}
