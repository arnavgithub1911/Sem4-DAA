#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void merge(int a[],int beg,int end,int mid)
{
	int i,j,k;
	int n1=mid-beg+1;
	int n2=end-mid;
	int leftarr[n1],rightarr[n2];
	for(i=0;i<mid;i++)
	{
		leftarr[i]=a[mid+i];
	}
	for(j=0;j<end;j++)
	{
		rightarr[j]=a[mid+1+j];
	}
	i=0;
	j=0;
	k=beg;
	while(i<n1&&j<n2)
	{
		if(leftarr[i]<rightarr[j])
		{
			a[k]=leftarr[i];
			i++;
		}
		else
		{
			a[k]=rightarr[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=leftarr[i];
		i++;
		k++;	
	}
	while(j<n2)
	{
		a[k]=rightarr[j];
		j++;
		k++;
	}
}
void mergesort(int a[],int l,int u)
{
	if(l<u)
	{
		int mid=(u-l)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,u);
		merge(a,l,u,mid);
	}
}
int partition(int a[],int l,int u)
{
	int temp,t;
	int i=l-1;
	int pivot=a[u];
	for(int j=l;j<u;j++)
	{
		if(a[j]<pivot)
		{
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}	
	temp=a[i+1];
	a[i+1]=a[u];
	a[u]=temp;
	return (i+1);
}
void quick(int a[],int l,int u)
{
	if(l<u)
	{
		int p=partition(a,l,u);
		quick(a,l,p);
		quick(a,p+1,u);
	}
}
void main()
{
	long int n=0;
	for(int k=0; k<(100000/100); k++)
	{
		n=n+100;
		int num[n];
		int quicksort[n];
		int merge[n];
		int j, min;
		clock_t start_t, end_t;
   		double total_t;
		printf("%ld\t",n);
		for(int i=0; i<n; i++)
		{
			num[i]=rand() % 10;
			merge[i]=num[i];
			quicksort[i]=num[i];
		}
		start_t = clock();
		mergesort(merge, 0 ,n-1);
		end_t = clock();
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("%lf\t", total_t );
		start_t = clock();
		quick(quicksort, 0 ,n-1);
		end_t = clock();
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("%lf\n", total_t );
	}
}
