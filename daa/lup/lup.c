#include<stdio.h>
#include<stdlib.h>

float **m;
FILE *fp;

float absolute(float a)
{
	if(a>=0)
		return a;
	else
		return -a;
}

int main()
{

	int i,j,k,kd,n;
	float P,tempo;			// identifies what maximum value is needed to be replaced
	char temp[10];

	fp=fopen("input.txt","r");
	fscanf(fp,"%s",temp);
	n=atoi(temp);

	m=(float **)(malloc(n*sizeof(float *)));
	for(i=0;i<n;i++)
		m[i]=(float *)(malloc(n*sizeof(float)));

	float b[n];
	int parent[n][n];
	float L[n][n],U[n][n];

// input from file

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%s",temp);
			m[i][j]=atof(temp);
			if(i==j)
				parent[i][j]=1;
			else
				parent[i][j]=0;
		// initialize L lower & U upper triangular matrix
			if(i==j)
				L[i][j]=1;
			else
				L[i][j]=0;
			U[i][j]=0;
		}
	}

	for(i=0;i<n;i++)
	{
		fscanf(fp,"%s",temp);
		b[i]=atof(temp);
	}

	fclose(fp);

	fp=fopen("output.txt","w");

// print input
fprintf(fp,"Input Matrix:\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(fp,"%f\t",m[i][j]);
			
		}
	fprintf(fp,"\n");
	}

fprintf(fp,"\nParent Matrix:\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(fp,"%d\t",parent[i][j]);
			
		}
	fprintf(fp,"\n");
	}

fprintf(fp,"\nConstant Matrix b:\n\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%f\t",b[i]);
	}
fprintf(fp,"\n\n");

// step 3 of algorithm

	for(k=0;k<n;k++)
	{
		// step 3.1
		P=0;
		// step 3.2
		for(i=k;i<n;i++)
		{
			if(absolute(m[i][k])>P)
			{
				P=absolute(m[i][k]);
				kd=i;			// kd = k'
			}
		}
		// step 3.3 check for det(matrix)=0
		if(P=0)
		{
			fprintf(fp,"singular matrix\n");
			exit(1);
		}
		// step 3.4 exchange parent k -> kd
		for(j=0;j<n;j++)
		{
			tempo=parent[k][j];
			parent[k][j]=parent[kd][j];
			parent[kd][j]=tempo;
		}
		// step 3.5 exchange parent k -> kd
		for(j=0;j<n;j++)
		{
			tempo=m[k][j];
			m[k][j]=m[kd][j];
			m[kd][j]=tempo;
		}
		// step 3.6 update matrix accordingly
		for(i=k+1;i<n;i++)
		{
			m[i][k]=m[i][k]/m[k][k];
			for(j=k+1;j<n;j++)
				m[i][j]=m[i][j]-m[i][k]*m[k][j];
		}

		// print intermediate
	
		fprintf(fp,"k = %d Input Matrix:\n\n",k);
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					fprintf(fp,"%f\t",m[i][j]);
					
				}
			fprintf(fp,"\n");
			}
		
		fprintf(fp,"\nk = %d Parent Matrix:\n\n",k);
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					fprintf(fp,"%d\t",parent[i][j]);
					
				}
			fprintf(fp,"\n");
			}

	}

	// L and U matrices updation

	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
			L[i][j]=m[i][j];
		for(k=i;k<n;k++)
			U[i][k]=m[i][k];
	}

	// solve LUP algorithm
	float x[n],y[n];	


	// printf L
	fprintf(fp,"\nL matrix\n\n");
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				fprintf(fp,"%f\t",L[i][j]);
			}
		fprintf(fp,"\n");
		}

	// printf U
	fprintf(fp,"\nU matrix\n\n");
	for(i=0;i<n;i++)
		{
		// initialize x & y matrices by 0
			x[i]=0;
			y[i]=0;
			for(j=0;j<n;j++)
			{
				fprintf(fp,"%f\t",U[i][j]);
			}
		fprintf(fp,"\n");
		}

	// update y matrix
fprintf(fp,"\ny matrix:\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(parent[i][j]==1)
				k=j;
		}
		tempo=0;
		for(j=0;j<=i-1;j++)
			tempo+=L[i][j]*y[j];
		y[i]=b[k]-tempo;
	fprintf(fp,"y[%d]=%f,b[%d]=%f,tempo=%f\t",i,y[i],k,b[k],tempo);
	}

	// update x matrix
fprintf(fp,"\nx matrix:\n\n");
	for(i=n-1;i>=0;i--)
	{
		tempo=0;
		for(j=i+1;j<n;j++)
			tempo+=U[i][j]*x[j];
		x[i]=(y[i]-tempo)/U[i][i];
	fprintf(fp,"y[%d]=%f,b[%d]=%f,tempo=%f\t",i,x[i],i,y[i],tempo);
	}

	free(m);
	fclose(fp);
return 0;
}
