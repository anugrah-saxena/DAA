#include<stdio.h>
void shiftdown(int [],int ,int );
void heapsort(int [],int );
void heapsort(int a[],int n)
{
	int i,temp;
	for(i=n/2;i>=1;i--)
	 {
		 shiftdown(a,i,n);
	 }
	 for(i=n;i>=1;i--)
	  {
		  temp=a[1];
		  a[1]=a[i];
		  a[i]=temp;
		  shiftdown(a,1,i-1);
	  }
}
void shiftdown(int a[],int root,int bottom)
{
	int maxchild,temp;
	while(root*2<=bottom)
	 {
		 if(root*2==bottom)
			 maxchild=root*2;
		 else if(a[root*2]>a[root*2+1])
			 maxchild=root*2;
		 else
			 maxchild=root*2+1;
		 if(a[root]<a[maxchild])
		  {
			  temp=a[root];
			  a[root]=a[maxchild];
			  a[maxchild]=temp;
			  root=maxchild;
		  }
		 else
			  break;
	 }
}
int main()
{
	int a[50],n,i;
	printf("enter size");
	scanf("%d",&n);
	printf("enter elements");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	printf("after heapsort the array is\n");
	for(i=1;i<=n;i++)
		printf("%d-",a[i]);
	return 0;
}
