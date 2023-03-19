#include<stdio.h>
#include<math.h>
#include<limits.h>
int MCM(int a[],int i,int j)
{
    if(i==j)
    {
        return 0;
    }
    int k;
    int min=INT_MAX;
    int count;
    for(k=i;k<j;k++)
    {
        count=MCM(a,i,k)+MCM(a,k+1,j)+a[i-1]*a[k]*a[j];
        if(count<min)
        {
            min=count;
        }
    }
    return min;
}
int main()
{
    int n,i,j;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=rand()%50;
    }
    printf("Array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    int N=sizeof(a)/sizeof(a[0]);
    printf("\nMinimum number of multiplications is %d.\n",MCM(a,1,n-1));
	return 0;
}
