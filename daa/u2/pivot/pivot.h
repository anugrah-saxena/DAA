int *pivot(int *a, int n)
{
	int i,j,k=n-1,npivot=0,*b;
	b=(int *)malloc(n*sizeof(int));
	for(i=n-2;i>=0;i--)
	{
		//finding lead here
		if(a[k]<a[i])
		{
			k=i;
			for(j=0;j<i;j++)
			{
				if(a[j]>=a[i])
				{
					b[npivot]=a[i];
					npivot++;
					break;
				}
			}	
		}
	}
	return b;
}
