#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "link.h"

// linklist will be of 2*n-1 nodes comprising the primitive characters n their frequencies and then coupled nodes from them
struct node *p;

struct node *p1;
struct node *p2;

FILE *fp;

// structure of characters witb their frequencies required for generating huffman code
typedef struct huffman
{
	char item[10];
	int freq;
	char huffcode[10];
}huffman;

int main()
{
	int i,j,k,n,tempo;
	char temp[10];
	p=NULL;

	fp=fopen("input.txt","r");
	fscanf(fp,"%s",temp);
	n=atoi(temp);

	huffman H[n];
	int flag[n];

	// input from file
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%s",H[i].item);
		fscanf(fp,"%s",temp);
		H[i].freq=atoi(temp);
		flag[i]=0;
	}

	fclose(fp);

	fp=fopen("output.txt","w");

	// print file input
	for(i=0;i<n;i++)
		fprintf(fp,"[index %d]... item->%s\tfreq->%d\n",i,H[i].item,H[i].freq);

	// min priority generation
	for(i=0;i<n;i++)
	{
		tempo=1000;
		for(j=0;j<n;j++)
		{
			if(flag[j]==0&&H[j].freq<tempo)
			{
				tempo=H[j].freq;
				k=j;
			}
		}
		flag[k]=1;
		// add node to linklist with frequency of smallest element
		append(&p,H[k].freq);
	}

	printf("\nindexes of nodes according to their frequency in min-priority queue is:\n");
	traverse(p);
	fprintf(fp,"\n\nallocating new nodes\n");

	// creating the tree like structure of a linklist with 2*n-1 nodes
	p2=p;
	p1=p2->link;

	for(i=0;i<n-1;i++)
	{
		tempo=p1->info+p2->info;
		fprintf(fp,"\np2->%d,p1->%d,tempo->%d\n",p2->info,p1->info,tempo);
		addsort(&p,tempo);
		p2=p1->link;
		p1=p2->link;
	}

	printf("\n\ntraverse of the linklist:\n");
	traverse(p);

	printf("\n\nreverse of the linklist:\n");
	reverse(&p);
	traverse(p);
	printf("\n");

	// huffman code
	p1=p;
	p2=p1->link;
	p1=p2->link;

	p->s[10]="",p1->s[10]="",p2->s[10]="";

	fprintf(fp,"\nIntermediate Steps:\n\n");

	while(p1!=NULL&&p2!=NULL)
	{
		fprintf(fp,"0	---ps%d---,---p2s%d---,---p1s%d---\n",p->info,p2->info,p1->info);
		if(p->info!=(p1->info+p2->info))
			p=p->link;
		strcpy(p2->s,p->s);
		strcat(p2->s,"1");
		strcpy(p1->s,p->s);
		strcat(p1->s,"0");

		fprintf(fp,"1	[ps%d->%s],[p2s%d->%s],[p1s%d->%s]\n",p->info,p->s,p2->info,p2->s,p1->info,p1->s);

		for(i=0;i<n;i++)
		{
			if(H[i].freq==p1->info&&flag[i]==1)
			{
				strcpy(H[i].huffcode,p1->s);
				flag[i]=0;
			}
			if(H[i].freq==p2->info&&flag[i]==1)
			{
				strcpy(H[i].huffcode,p2->s);
				flag[i]=0;
			}
		}

		p=p->link;
		p2=p1->link;
		if(p2==NULL)
			break;
		p1=p2->link;		
		fprintf(fp,"11	---ps%d---,---p2s%d---,---p1s%d---\n",p->info,p2->info,p1->info);
	}

	fprintf(fp,"\n\n\tFinal Huffman code:\n\n");
	fprintf(fp,"\tItem\tFrequency\tHUFFMAN Code\n");

	for(i=0;i<n;i++)
		fprintf(fp,"\t%s\t%d\t\t%s\n",H[i].item,H[i].freq,H[i].huffcode);

	fclose(fp);

return 0;
}
