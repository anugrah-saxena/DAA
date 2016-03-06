// strassen matrix works for nxn order matrix only with n be power of 2
#include<stdio.h>
#include<stdlib.h>

int **m1;
int **m2;
FILE *fp;

int main()
{

	int n;
	int R,C;
	int P[7];
	int a,b,c,d,e,f,g,h;
	char temp[10];
	fp=fopen("input.txt","r");

	fscanf(fp,"%s",temp);
	n=atoi(temp);

	m1=(int **)(malloc)(n*(sizeof(int *)));
	for(R=0;R<n;R++)
		m1[R]=(int *)(malloc)(n*sizeof(int));

	m2=(int **)(malloc)(n*(sizeof(int *)));
	for(R=0;R<n;R++)
		m2[R]=(int *)(malloc)(n*sizeof(int));

	for(R=0;R<n;R++)
		for(C=0;C<n;C++)
		{
			fscanf(fp,"%s",temp);
			m1[R][C]=atoi(temp);
		}

	for(R=0;R<n;R++)
		for(C=0;C<n;C++)
		{
			fscanf(fp,"%s",temp);
			m2[R][C]=atoi(temp);
		}

	fclose(fp);

// input is
printf("m1:\n");
	for(R=0;R<n;R++)
	{
		for(C=0;C<n;C++)
		{
			printf("%d\t",m1[R][C]);
		}
	printf("\n");
	}
printf("m2:\n");
	for(R=0;R<n;R++)
	{
		for(C=0;C<n;C++)
		{
			printf("%d\t",m2[R][C]);
		}
	printf("\n");
	}

	int m[n][n];

	a=m1[0][0];	b=m1[0][1];	c=m1[1][0];	d=m1[1][1];
	e=m2[0][0];	f=m2[0][1];	g=m2[1][0];	h=m2[1][1];
	
	P[0]=a*(f-h);	P[1]=(a+b)*h;	P[2]=(c+d)*e;	P[3]=d*(g-e);	P[4]=(a+d)*(e+h);	P[5]=(b-d)*(g+h);	P[6]=(a-c)*(e+f);
	
printf("P:\n");
	for(R=0;R<7;R++)
		printf("P%d = %d\n",R,P[R]);

	m[0][0]=P[4]+P[3]-P[1]+P[5];
	m[0][1]=P[0]+P[1];
	m[1][0]=P[2]+P[3];
	m[1][1]=P[4]+P[0]-P[2]-P[6];

printf("m:\n");
	for(R=0;R<n;R++)
	{
		for(C=0;C<n;C++)
		{
			printf("%d\t",m[R][C]);
		}
	printf("\n");
	}


//end
	free(m1);	free(m2);
return 0;
}
