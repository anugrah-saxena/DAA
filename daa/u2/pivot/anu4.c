#include<stdio.h>
#include<stdlib.h>
#include "pivot.h"
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
	printf("\npivots in the array are:");
	b=pivot(a,n);
	j=0;

	while(b[j]!=0)
	{
		printf("\t%d",b[j]);
		j++;
	}
	printf("\ntotal number of pivots are:\t%d\n",j);

}
