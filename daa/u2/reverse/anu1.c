#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char text[1000];
	char rev[1000];
	char temp[100][20];
	int i,k=0,j,y=1,n,flag=0;
	
	printf("enter the string:\n");
	gets(text);
	
	printf("\ninput string is:\t");
	puts(text);

	n=strlen(text);
	temp[k][0]=' ';
	for(i=0;i<n;i++)
	{
		if(text[i]==' ')
		{
			temp[k++][y++]='\0';
			flag=1;
			temp[k][0]=text[i];
			y=1;
		}
		else
		{	
			temp[k][y++]=text[i];
		}
	}
	for(i=k;i>=0;i--)
	{
		strcat(rev,temp[i]);
	}
	rev[n+1]='\0';	
	printf("reverse of string is:\t");
	puts(rev);	
}
