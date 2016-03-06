// wt infinite = 1000 parent NIL = -1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int **w;
//int *s;
//int **parent;
//int *distance;
FILE *fp,*out;
int main()
{
	int temp1[10];
	int i,j,k,n,count=0;
	int u,v;
	char temp[10];
	fp=fopen("input.txt","r");
	out=fopen("output.txt","w");

// finding no of rows in thhe given weight graph
	do
	{
		count++;
//	printf("%d\n",count);
	}while((fscanf(fp,"%d",temp1))!=EOF);
	n=sqrt(count);

	fprintf(out,"n = %d\n\n",n);

	int parent[n][n];
	int tempo[n][n];

	w=(int **)(malloc(n*sizeof(int *)));
	for(i=0;i<n;i++)
		w[i]=(int *)(malloc(n*sizeof(int)));

//	s=(int *)(malloc(1*sizeof(int)));

//	parent=(int **)(malloc(n*sizeof(int *)));
//		parent[i]=(int *)(malloc(n*sizeof(int)));

//	distance=(int *)(malloc(n*sizeof(int)));

// point to the start of file again
rewind(fp);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%s",temp);
			w[i][j]=atoi(temp);
	// initialize parent matrix
			if(w[i][j]!=1000&&i!=j)
				parent[i][j]=i+1;
			else
				parent[i][j]=-1;
		tempo[i][j]=w[i][j];
		}
	}
fclose(fp);

fprintf(out,"initial value of W0 & P0 matrix\n\n");

	// weight matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(out,"w=%d\t",w[i][j]);
		}
	fprintf(out,"\n");
	}


	// parent matrix
	fprintf(out,"\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(out,"p=%d\t",parent[i][j]);
		}
	fprintf(out,"\n");
	}
//printf("n=%d\n",n);

	// iteration by algorithm
	for(k=0;k<n;k++)
	{
//printf("k=%d\n",k);
		for(i=0;i<n;i++)
		{
//printf("i=%d\n",i);
			for(j=0;j<n;j++)
			{
//printf("j=%d\n",j);
			if(i==j)continue;
//	printf("%d	t %d, %d = %d p = %d\n",k,i,j,tempo[i][j],parent[i][j]);
//				if(w[i][j]=<(w[i][k]+w[k][j]))
//				{
//					tempo[i][j]=w[i][j];
//				}
				if(w[i][j]>(w[i][k]+w[k][j]))
				{
					if(w[i][k]==1000||w[k][j]==1000)
						tempo[i][j]=1000;
					else
					{
						tempo[i][j]=w[i][k]+w[k][j];
						parent[i][j]=parent[k][j];
					}
				}

//	printf("%d	t %d, %d = %d p = %d\n",k,i,j,tempo[i][j],parent[i][j]);

			}
		}
			// write intermediate step to file and update weight
				fprintf(out,"updated value of W%d & P%d matrix\n\n",k+1,k+1);
					for(u=0;u<n;u++)
					{
						for(v=0;v<n;v++)
						{
							w[u][v]=tempo[u][v];
							fprintf(out,"w=%d\t",w[u][v]);
						}
					fprintf(out,"\n");
					}
				// parent matrix
				fprintf(out,"\n");
				for(u=0;u<n;u++)
				{
					for(v=0;v<n;v++)
					{
						fprintf(out,"p=%d\t",parent[u][v]);
					}
				fprintf(out,"\n");
				}
				
	}


	free(w);	/*free(parent);*/		//free(distance);		//free(s);

	fclose(out);
return 0;
}
