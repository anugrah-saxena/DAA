#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<time.h>
//#include<math.h>
void selection(int [],int );
void insertion(int [],int );
void bubble(int [],int );
void merge(int [],int ,int ,int );
void mergeall(int [],int ,int ,int ,int ,int );
int part(int [],int ,int );
void quick(int [],int ,int );
int main()
{
        struct timeval tim;
        double t1,t2;
	int n;
	printf("enter no. of array elements: ");
	scanf("%d",&n);

	int a[n],i;
	int ch;
	// array input
	for(i=0;i<n;i++)
	{
//		printf("enter a[%d]: ",i);
//		scanf("%d",&a[i]);
		a[i]=rand();
	}
	do
	{
		printf("\n------select sorting method------\n");
		printf("1. selection sort\n2. insertion sort\n3. bubble sort\n4. merge sort\n5. quick sort\n6. output\n");
		printf("enter your choice:\t");
		scanf("%d",&ch);

		
		switch(ch)
		{
			case 1:
				printf("array sorting by selection sort\n");
             gettimeofday(&tim, NULL);
              t1=tim.tv_sec+(tim.tv_usec/1000000.0);

				selection(a,n);
             gettimeofday(&tim, NULL);
              t2=tim.tv_sec+(tim.tv_usec/1000000.0);
             printf("%9lf micro seconds elapsed for program\n",(t2-t1)*1000000);


				break;
			case 2:
				printf("array sorting by insertion sort\n");
             gettimeofday(&tim, NULL);
              t1=tim.tv_sec+(tim.tv_usec/1000000.0);

				insertion(a,n);
             gettimeofday(&tim, NULL);
              t2=tim.tv_sec+(tim.tv_usec/1000000.0);
             printf("%9lf micro seconds elapsed for program\n",(t2-t1)*1000000);


				break;
			case 3:
				printf("array sorting by bubble sort\n");
             gettimeofday(&tim, NULL);
              t1=tim.tv_sec+(tim.tv_usec/1000000.0);

				bubble(a,n);
             gettimeofday(&tim, NULL);
              t2=tim.tv_sec+(tim.tv_usec/1000000.0);
             printf("%9lf micro seconds elapsed for program\n",(t2-t1)*1000000);

				break;
			case 4:
				printf("array sorting by merge sort\n");
             gettimeofday(&tim, NULL);
              t1=tim.tv_sec+(tim.tv_usec/1000000.0);

				merge(a,0,n-1,n);
             gettimeofday(&tim, NULL);
              t2=tim.tv_sec+(tim.tv_usec/1000000.0);
             printf("%9lf micro seconds elapsed for program\n",(t2-t1)*1000000);

				break;
			case 5:
				printf("array sorting by quick sort\n");
             gettimeofday(&tim, NULL);
              t1=tim.tv_sec+(tim.tv_usec/1000000.0);

				quick(a,0,n-1);
             gettimeofday(&tim, NULL);
              t2=tim.tv_sec+(tim.tv_usec/1000000.0);
             printf("%9lf micro seconds elapsed for program\n",(t2-t1)*1000000);
				break;
			case 6:
//				printf("output array: ");
				break;
			default:
				printf("incorrect entry");
		}
	}while(ch!=6);		
	//  output array
/*	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
*/
return 0;
}
void selection(int a[],int n)
{
	int i,j,imin;
	int temp;
	for(i=0;i<n-1;i++)
	{
		imin=i;
		for(j=i+1;j<n;j++)
		{
			if(a[imin]>a[j])
				imin=j;
		}
 		if(i!=imin)
		{
			temp=a[i];
			a[i]=a[imin];
			a[imin]=temp;
		}
	}
}

void insertion(int a[],int n)
{
	int i,j;
	int item;
	for(i=1;i<n;i++)
	{
		item=a[i];
		for(j=i-1;j>=0&&a[j]>item;j--)
			a[j+1]=a[j];
		a[j+1]=item;
	}
}
void bubble(int a[],int n)
{
	int i,j;
	int temp,flag=1;
	for(i=1;i<n&&flag==1;i++)
	{
		flag=0;
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
	}
}
void merge(int a[],int l,int u,int n)
{
	int mid;
	if(l<u)
	{
		mid=(l+u)/2;
		merge(a,l,mid,n);
		merge(a,mid+1,u,n);
		mergeall(a,l,mid,mid+1,u,n);
	}
}
void mergeall(int a[],int l1,int u1,int l2,int u2,int n)
{
	int i,j,k;
	int temp[n];
	for(i=l1,j=l2,k=l1;i<=u1&&j<=u2;k++)
	{
		if(a[i]<a[j])
			temp[k]=a[i++];
		else
			temp[k]=a[j++];
	}
	while(i<=u1)
			temp[k++]=a[i++];
	while(j<=u2)
			temp[k++]=a[j++];
	for(i=l1;i<=u2;i++)
		a[i]=temp[i];
}
void quick(int a[],int l,int u)
{
	int mid;
	if(l>=u)
		return;
	mid=part(a,l,u);
	quick(a,l,mid-1);
	quick(a,mid+1,u);
}
int part(int a[],int l,int u)
{
	int down,up,t,pivot;
	down=l;
	up=u;
	pivot=a[l];
	while(down<up)
	{
		while(a[down]<=pivot&&down<up)
			down++;
		while(a[up]>pivot)
			up--;
		if(down<up)
		{
			t=a[down];
			a[down]=a[up];
			a[up]=t;
		}
	}
	a[l]=a[up];
	a[up]=pivot;
	return(up);
}
