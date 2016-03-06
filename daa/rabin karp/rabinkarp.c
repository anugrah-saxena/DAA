#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char text[100];
char pattern[100];
FILE *fp;

int mod(int ,int );

int main()
{

	int i,j,l1,l2;
	int iz,a,b,flag=0;
	int tex=0,pat,pmod;
	char temp[10];

	fp=fopen("input.txt","r");

	fscanf(fp,"%s",text);
	fscanf(fp,"%s",pattern);
	fscanf(fp,"%s",temp);
	b=atoi(temp);

	l1=strlen(text);
	l2=strlen(pattern);

	fclose(fp);

	fp=fopen("output.txt","w");

	pat=mod(atoi(pattern),b);
	fprintf(fp,"pat%d<-b%d\n",pat,b);

	for(i=0;i<l2;i++)
	{
		tex=tex*10+text[i]-'0';
	}

	pmod=pow(10,l2-1);
	fprintf(fp,"tex->%d,pmod->%d,pat->%d,b->%d\n",tex,pmod,pat,b);

	fprintf(fp,"\nNow the intermediate steps:\n\n");

	// rabin karp algorithm
	for(i=0;i<l1-l2+1;i++)
	{
		flag=0;
		a=mod(tex,b);
		fprintf(fp,"tex->%d,a->%d\n",tex,a);
		if(a==pat)
		{
			for(j=0;j<l2;j++)
			{
				if(text[i+j]!=pattern[j])
					flag=1;
				if(j==l2-1&&flag==0)
					fprintf(fp,"\nFinal Output:\n\n[matched pattern\t%d]\n",tex);
			}
		}
		if(flag==1)
			fprintf(fp,"\n[spurious hit\t%d]\n\n",tex);
		tex=10*(tex%pmod)+text[i+l2]-'0';
	}

	fclose(fp);

return 0;
}
int mod(int a,int b)
{
	return a%b;
}
