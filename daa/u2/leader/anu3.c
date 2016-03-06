#include<stdio.h>
#include<stdlib.h>
#include "leader.h"
void main()
{
	int i,j,k,n,*b;
	printf("\nenter the number of elements of the array:");
	scanf("%d",&n);
	int a[n];
	printf("\nenter %d elements of the array\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("array is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	b=leader(a,n);
	j=0;
	printf("\nleaders in the array are:");
	while(b[j]!=0)
	{
		printf("\t%d",b[j]);
		j++;
	}
	printf("\ntotal number of leaders are:\t%d\n",j);
}
