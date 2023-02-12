#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void insertion(long int n,long int a[])
{
    long int i,j,temp;
    for(i=0;i<n;i++)
    {
    	temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
        	a[j+1]=a[j];
        	j--;
        }
        a[j+1]=temp;     
    }                  
}
void selection(long int n,long int a[])
{
	long int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			temp=a[min];
			a[min]=a[i];
			a[i]=temp;
		}
	}    
}
void main()
{
    	long int i,t=0,n=100,numbers;
	double time1[10],time2[10];
	printf("intervals\tInsertion\t\tSelection\n");
	while(t++<1000)
	{
		long int b[n],c[n];
    		for(int i=0;i<n;i++)
    		{
			srand(time(NULL));   
        		numbers=(rand()%100000);
        		b[i]=numbers;
			c[i]=numbers;
    		}
		clock_t end,start;
        	start=clock();
        	insertion(n,b);
        	end=clock();
		time1[t]=((double)(end-start)/CLOCKS_PER_SEC);
		start=clock();
       		selection(n,c);
       		end=clock();
		time2[t]=((double)(end-start)/CLOCKS_PER_SEC);
        	printf("%li\t\t%lf\t\t%lf\n",n,time1[t]+=((double)(end-start)/CLOCKS_PER_SEC),time2[t]+=((double)(end-start)/CLOCKS_PER_SEC));  
		n+=100;      
     	}
}

        
            
