#include<stdio.h>
#include<stdlib.h>
void main()
{
	int size,i,k;
	int max,min;
	char temp[10];
	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%s",temp);
	size=atoi(temp);
//	printf("no of elements in array = %d\n",size);

	int a[size];

	for(i=0;i<size;i++)
	{
		fscanf(fp,"%s",temp);
		a[i]=atoi(temp);
	}
	fclose(fp);

	int b[size+1];
	for(i=0;i<size+1;i++)
		b[i]=0;

	fp=fopen("output.txt","w");

	max=min=a[0];
	for(i=1;i<size;i++)
	{
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}

	k=max-min+1;
	fprintf(fp, "size of frequency matrix = %d\n",k);

//	k=max-1;
	int c[k+1];
	for(i=0;i<k+1;i++)
		c[i]=0;

	fprintf(fp, "frequency matrix is:\n");
	for(i=0;i<size;i++)
	{
		c[a[i]]=c[a[i]]+1;
		fprintf(fp, "%d\t",c[a[i]]);
	}

	fprintf(fp, "\ncummulative frequency matrix is:\n%d(''0'')\t",c[0]);
	for(i=1;i<k+1;i++)
	{
		c[i]=c[i]+c[i-1];
		fprintf(fp, "%d(''%d'')\t",c[i],i);
	}
	fprintf(fp, "\n\nintermediate begin>>>\n");
	for(i=size-1;i>=0;i--)
	{
	fprintf(fp, "[before assigning]:\t(array b)%d & (array c)%d & (array a)%d & (index i)%d\n",b[c[a[i]]],c[a[i]],a[i],i);
		b[c[a[i]]]=a[i];
		c[a[i]]=c[a[i]]-1;
	fprintf(fp, "[after  assigning]:\t(array b)%d & (array c)%d & (array a)%d & (index i)%d\n",b[c[a[i]]],c[a[i]],a[i],i);
	}
	fprintf(fp, ">>>end intermediate\n");

	fprintf(fp, "\noutput sorted matrix is:\n");
	for(i=1;i<size+1;i++)
	{
		fprintf(fp,"%d\t",b[i]);
	}
	fclose(fp);
}
