#include<stdio.h>
#define MAX 10

void BuildMaxHeap(int *,int);
void MaxHeap(int *,int,int);
void main()
{
	int a[MAX];
	int n,i,j,n1,t;

	printf("Enter no. of elements :	");
	scanf("%d",&n);
	n1=n;

	for(i=1;i<=n;i++)
	{
		printf("Enter %d element :\t",i);
		scanf("%d",&a[i]);
	}
	
	BuildMaxHeap(a,n);

	for(i=n;i>0;i--)
	{
		t=a[i];
		a[i]=a[1];
		a[1]=t;
		n1=n1-1;

		MaxHeap(a,n1,1);
	}

	printf("Sorted array");

	for(i=1;i<=n;i++)
	{
		printf("\n%d",a[i]);
	}
}
	
void BuildMaxHeap(int a[],int n)
{
	int i,tmp;
	tmp=n/2;

	for(i=tmp;i>0;i--)
	{
		MaxHeap(a,n,i);
	}
}

void MaxHeap(int a[],int n,int i)
{
	int l,r,largest,t;
	l=2*i;
	r=l+1;

	if(l<n && a[l]>a[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	
	if(r<n && a[r]>a[largest])
	{
		largest=r;
	}

	if(largest!=i)
	{
		t=a[i];
		a[i]=a[largest];
		a[largest]=t;
		MaxHeap(a,n,largest);
	}
}	
