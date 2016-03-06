int *leader(int *a, int n)
{
	int k,l,*b,nlead=0;
	k=n-1;
	b=(int *)malloc(n*sizeof(int));
	for(l=k-1;l>=0;l--)
	{
		if(a[k]<a[l])
		{
			b[nlead]=a[l];
			k=l;
			nlead++;		
		}
	}
	return b;
}
