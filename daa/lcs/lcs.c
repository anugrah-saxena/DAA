#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **c;
int **dir;
char text[100];
char pattern[100];
FILE *fp;

void print_lcs(int ,int );

int main()
{

	int i,j,l1,l2;

	fp=fopen("input.txt","r");

	fscanf(fp,"%s",text);
	fscanf(fp,"%s",pattern);

	l1=strlen(text);
	l2=strlen(pattern);

	fclose(fp);

	fp=fopen("output.txt","w");

	fprintf(fp,"l1=%d l2=%d\n",l1,l2);

	l1++;	l2++;

	c=(int **)(malloc)(l1*sizeof(int *));
	for(i=0;i<l1;i++)
		c[i]=(int *)(malloc)(l2*sizeof(int));

	dir=(int **)(malloc)(l1*sizeof(int *));
	for(i=0;i<l1;i++)
		dir[i]=(int *)(malloc)(l2*sizeof(int));		// -10=no direction -1=left 0=diagonal 1=up

/*	for(i=0;i<l1-1;i++)
		printf("%d\t",text[i]);
printf("\n");
	for(j=0;j<l2-1;j++)
		printf("%d\t",pattern[j]);
printf("\n");

	if(text[0]==pattern[1])
		printf("hello");
	else
		printf("bye");
*/


	for(i=0;i<l1;i++)
	{
		c[i][0]=0;
		dir[i][0]=-10;
	}

	for(j=0;j<l2;j++)
	{
		c[0][j]=0;
		dir[0][j]=-10;
	}

	for(i=1;i<l1;i++)
	{
		for(j=1;j<l2;j++)
		{
//printf("0\ti=%d j=%d texti=%c patternj=%c cij=%d dirij=%d\n",i,j,text[i-1],pattern[j-1],c[i][j],dir[i][j]);
			if(text[i-1]==pattern[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				dir[i][j]=0;			// diagonal
			}
			if(text[i-1]!=pattern[j-1])
			{
				if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					dir[i][j]=1;		// default up
				}
				else
				{
					c[i][j]=c[i][j-1];
					dir[i][j]=-1;		// left
				}

			}
//printf("1\ti=%d j=%d texti=%c patternj=%c cij=%d dirij=%d\n",i,j,text[i-1],pattern[j-1],c[i][j],dir[i][j]);
		}
	}

// print c & dir
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
		{
			fprintf(fp,"(%d,",c[i][j]);
			if(dir[i][j]==-10)
				fprintf(fp,"no");
			else if(dir[i][j]==-1)
				fprintf(fp,"lt");
			else if(dir[i][j]==0)
				fprintf(fp,"di");
			else
				fprintf(fp,"up");
			fprintf(fp,")\t");
		}
		fprintf(fp,"\n\n");
	}

//	printf LCS pass in initial call direction matrix and text string if local ; and length of text (l1~updated -1) & length of pattern (l2~updated -1)
	fprintf(fp,"Longest Common Subsequence:\t");
	print_lcs(l1-1,l2-1);

	fclose(fp);


return 0;
}
void print_lcs(int i,int j)
{
//printf("i=%d j=%d dirij=%d texti='%c'\n",i,j,dir[i][j],text[i-1]);
	if(i==0||j==0)
		return;
	if(dir[i][j]==0)	//diagonal
	{
		print_lcs(i-1,j-1);
		fprintf(fp,"%c",text[i-1]);
	}
	else if(dir[i][j]==1)	//up
		print_lcs(i-1,j);
	else
		print_lcs(i,j-1);	//left
}
