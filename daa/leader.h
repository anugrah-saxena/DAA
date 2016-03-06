int leader(int *a, int i, int n)
{
	int j,k,l,p;
	j=i;
	k=n-1;
	for(l=j+1,p=k;l<n,p>l;l++,p--)
	{
		if(a[l]>a[j])
		{
			if(a[p]>a[l])
			{
				j=p;
				break;
			}
			j=l;
		}
	}
	return j;
}

