// in matrix m 0 signifies no scalar multiplication required for that i & j pair
// in matrix s -1 represents that it is of no use in matrix multiplication

#include<stdio.h>
#include<stdlib.h>

int **m;
int **s;
FILE *fp,*fo;

void print_optimal_paranthesis(int ,int );

int main()
{

	int i,j,k,kd,n,temp1,tempo,count=1;
	char temp[10];

	// input for RXC values
	fp=fopen("input.txt","r");
	fscanf(fp,"%s",temp);
	n=atoi(temp);

	m=(int **)(malloc)(n*sizeof(int *));
	for(i=0;i<n;i++)
		m[i]=(int *)(malloc)(n*sizeof(int));
	s=(int **)(malloc)(n*sizeof(int *));
	for(i=0;i<n;i++)
		s[i]=(int *)(malloc)(n*sizeof(int));

	// array containing RXC values
	int A[n][2];
	int P[n+1];

	for(i=0;i<n;i++)
	{
		fscanf(fp,"%s",temp);
		A[i][0]=atoi(temp);
		fscanf(fp,"%s",temp);
		A[i][1]=atoi(temp);
		P[i+1]=A[i][1];
	}

	j=0;
	P[j]=A[j][0];

	fclose(fp);

	fp=fopen("output.txt","w");

	// print input
	fprintf(fp,"A RXC array\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			fprintf(fp,"%d\t",A[i][j]);
		}
	fprintf(fp,"\n");
	}

	fprintf(fp,"P array:\n\n");
	for(i=0;i<n+1;i++)
		fprintf(fp,"%d\t",P[i]);

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			m[i][j]=0;
			s[i][j]=-1;
		}

	// update m & s matrices
	while(count<n)
		for(i=0,j=i+count++;i<n&&j<n;i++,j++)
		{
			temp1=1000;
			for(k=i;k<=j-1;k++)
			{
				tempo=m[i][k]+m[k+1][j]+P[i]*P[j+1]*P[k+1];
				if(tempo<temp1)
				{
					temp1=tempo;
					kd=k;
				}
			}
			if(temp1==1000)
			{
				m[i][j]=0;
				s[i][j]=-1;
			}
			else
			{
				m[i][j]=temp1;
				s[i][j]=kd;
			}
	}

	// printf updated value
	fprintf(fp,"\n\nm matrix:\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(fp,"%d\t",m[i][j]);
		}
	fprintf(fp,"\n");
	}

	fprintf(fp,"\n\ns matrix:\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(fp,"%d\t",s[i][j]);
		}
	fprintf(fp,"\n");
	}



	// input for optimal paranthesis i & j values
	fo=fopen("optimalpath.txt","r");

	// print optimal paranthesis

	fscanf(fo,"%s",temp);
	i=atoi(temp);
	fscanf(fo,"%s",temp);
	j=atoi(temp);

	fprintf(fp,"\n\noptimal paranthesis :\t");

	// call to function
	print_optimal_paranthesis(i,j);
	fprintf(fp,"\n\n");

	fclose(fp);	fclose(fo);
	free(m);	free(s);		
return 0;
}
void print_optimal_paranthesis(int i,int j)
{
	if(i==j)
		fprintf(fp,"A%d",i);
	else
	{
		fprintf(fp,"(");
		print_optimal_paranthesis(i,s[i][j]);
		print_optimal_paranthesis(s[i][j]+1,j);
		fprintf(fp,")");
	}
}
