#include <stdio.h>

void merge(int arr[],int l,int mid, int r)
{
	int i=l, j=mid+1, k=0;
	
	int brr[r-l+1];
	
	while(i<=mid && j<=r)
	{
		if(arr[i]<=arr[j]){
			brr[k]=arr[i]; k++;i++;
		}
		
		else {
			brr[k]=arr[j];k++;j++;
		}
	}
	
	while(i<=mid){
		brr[k]=arr[i];k++;i++;
	}
	
	while(j<=r){
		brr[k]=arr[j];k++;j++;
	}
	printf("Temporary array:- ");
	for(int i=0;i<k;i++)
	{printf("%d ",brr[i]);
		arr[l+i]=brr[i];
	}
    printf("\n");
    
}

void mergesort(int arr[],int l,int r)
{
	if(l<r)
	{	int mid=(l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

int main()
{
	int arr[7]={9,4,7,6,3,1,5};
	printf("Before merge sorting");
	for(int i=0;i<7;i++)
	{
		printf("%d ",arr[i]);
	}
    
    printf("\n");
	mergesort(arr,0,6);
	
	printf("\nAfter merge sorting");
	
		for(int i=0;i<7;i++)
	{
		printf("%d ",arr[i]);
	}
	
    return 0;
    
}