#include<stdio.h>
#include<malloc.h>
void main()
{
	int *b,i,n,mid;
	printf("enter number of item\t");
	scanf("%d",&n);

	int a[n];
	printf("enter data in sorted order\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}


 	if(n%2==0)
		mid=(n/2)-1;
	else
		mid=n/2;

	printf("\nvalue with frequency > or = %d is :",mid);


	if(a[mid+1]!=a[mid-1])
	{
		if(a[0]==a[mid-1])
			printf("%d",a[mid-1]);
		else if(a[n-1]==a[mid+1])
			printf("%d",a[mid+1]);
		else
			printf("no such number found");
	}
	else
	{
 		if((a[mid-1]==a[(mid/2)-1])||(a[mid+1]==a[(mid+mid/2)+1]))
 			printf("%d",a[mid]);
 		else
 			printf("no such number found");
	}
	printf("\n");
}
