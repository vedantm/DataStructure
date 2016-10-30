#include<stdio.h>
int H[1000];
int heapsize = 0;

void InsertHeap(int x)
{
	int i,t,y;
	heapsize=heapsize+1;	
	H[heapsize] = x;
	i=(heapsize/2);
	y=heapsize;	
	while(i != 0)
	{
		if(H[i] < H[y])
		{
			t=H[i];
			H[i]=H[y];
			H[y]=t;
			i=i/2;
			y=y/2;
		}
		else 
			break;
	}	  
}

int MaxDelete()
{
	int i=1,t;	
	if(heapsize==1)
	{
		heapsize=0;
		return H[1];
	}
	t=H[heapsize];
	H[heapsize]=H[1];
	H[1]=t;
	heapsize=heapsize-1;	
	while((H[i] < H[2*i] && 2*i <=heapsize)|| (H[i] < H[2*i+1] && 2*i+1 <= heapsize))
	{
		if(2*i+1 > heapsize)
		{
			t=H[i];
			H[i]=H[2*i];
			H[2*i]=t;
			break;		
		}			
		else 
		{
			if(H[2*i+1] < H[2*i] )
			{
				t=H[i];
				H[i]=H[2*i];
				H[2*i]=t;		
				i=2*i;		
			}
			else 
			{
				t=H[i];
				H[i]=H[2*i+1];
				H[2*i+1]=t;		
				i=2*i+1;		
			}
		}		
	}
	return H[heapsize+1];
}

void PrintArray()
{
	int i;
	for(i=1;i<=heapsize;i++)
	{
		printf(" %d    ",H[i]);
	}
}

int main()
{
	int i,n,x,z;
	printf("Enter the value of n which is less than 1000 \n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the %d element =  ",i);
		scanf("%d",&x);		
		InsertHeap(x);
	}
	printf("\nHeap size is  = %d \n \n",heapsize);	
	printf("The resultant Heap is as follows \n ");	
	PrintArray();
	printf("\n \n");	
	printf("Array formed from deletion of max element \n");	
	for(i=1;i<=n;i++)
	{
		z=MaxDelete();
		printf("%d     ",z);	
	}
}
