#include <iostream>

using namespace std;
/* O(1) space complexity and more than O(NlongN) T.C*/
/*void inversion_count(int arr[],int l,int mid,int r,int *count_ptr);
void mergesort(int arr[],int l,int r,int *count_ptr);

int main()
{
//    int arr[]={4,1,3,2,5};
//        int arr[]={10,10,10};
//    int arr[]={2,3,4,5,6};
        int arr[]={2,4,1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int count=0;
    int *count_ptr=&count;
    mergesort(arr,0,n-1,count_ptr);
    
    cout<<"Inverseion count is:- "<<count<<endl;
    
    return 0;
}

void inversion_count(int arr[],int l,int mid,int r,int *count_ptr)
{
    int i=l,j=mid+1;
    int c=*count_ptr;
    
    while(i<=mid && j<=r)
    {
        if(arr[i]>arr[j] && j==r)
        {
            c++; i++;
        } 
        else if(arr[i]>arr[j] )
        { c++;j++; }
        
        else if(j==r && i<=mid)
        { i++; j=mid+1; }
        
        else if(arr[i]<arr[j] && i<=mid && j!=r)
            j++;
    }
    
    *count_ptr=c;
    cout<<"Temporary :- count = "<<*count_ptr<<endl;
}

void mergesort(int arr[],int l,int r,int *count_ptr)
{
        if(l<r)
        {
            int mid=(l+r)/2;
            mergesort(arr,l,mid,count_ptr);
            mergesort(arr,mid+1,r,count_ptr);
            inversion_count(arr,l,mid,r,count_ptr);
        }
} */
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
void inversion_count(int arr[],int l,int mid,int r,int *count_ptr);
void mergesort(int arr[],int l,int r,int *count_ptr);

int main()
{
// int arr[]={4,1,3,2,5};
//        int arr[]={10,10,10};
//    int arr[]={2,3,4,5,6};
//        int arr[]={2,4,1,3,5};
//int arr[]={5,3,2,4,1};
int size;
cout<<"Enter size "; cin>>size; int arr[size];
for(int i=0;i<size;i++)
    cin>>arr[i];
    
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int count=0;
    int *count_ptr=&count;
    mergesort(arr,0,n-1,count_ptr);
    
    cout<<"Inverseion count is:- "<<count<<endl;
    
    return 0;
}

void inversion_count(int arr[],int l,int mid,int r,int *count_ptr)
{
    int i=l,j=mid+1;
    int c=*count_ptr; int k=0;
    int brr[r-l+1];
     
    while(i<=(mid) && j<=r)
    {
       if(arr[i]<=arr[j])
           brr[k++]=arr[i++];
        else{
            brr[k++]=arr[j++];
            c=c+( (mid-i) +1);
        }
    }
    
    while(i<=mid)
        brr[k++]=arr[i++];
        
    while(j<=r)
        brr[k++]=arr[j++];
    
    for(int i=0;i<k;i++)
        arr[i+l]=brr[i];
    
    *count_ptr=c;
    cout<<"Temporary :- count = "<<*count_ptr<<endl;

}

void mergesort(int arr[],int l,int r,int *count_ptr)
{
        if(l<r)
        {
            int mid=(l+r)/2;
            mergesort(arr,l,mid,count_ptr);
            mergesort(arr,mid+1,r,count_ptr);
            inversion_count(arr,l,mid,r,count_ptr);
        }
}
/////////////////////////////////////////////////////////////////////////
////////////////////////////// ///////////////// //////////////////////////////////////// ///////////////////////////
//////////////////////////////////////////////////////////////////////////// ////////////   ////////////////////////////
// C++ program to Count
// Inversions in an array
// using Merge Sort
//#include <bits/stdc++.h>
//using namespace std;
//
//int _mergeSort(int arr[], int temp[], int left, int right);
//int merge(int arr[], int temp[], int left, int mid,
//		int right);
//
///* This function sorts the
//input array and returns the
//number of inversions in the array */
//int mergeSort(int arr[], int array_size)
//{
//	int temp[array_size];
//	return _mergeSort(arr, temp, 0, array_size - 1);
//}
//
///* An auxiliary recursive function
//that sorts the input array and
//returns the number of inversions in the array. */
//int _mergeSort(int arr[], int temp[], int left, int right)
//{
//	int mid, inv_count = 0;
//	if (right > left) {
//		/* Divide the array into two parts and
//		call _mergeSortAndCountInv()
//		for each of the parts */
//		mid = (right + left) / 2;
//
//		/* Inversion count will be sum of
//		inversions in left-part, right-part
//		and number of inversions in merging */
//		inv_count += _mergeSort(arr, temp, left, mid);
//		inv_count += _mergeSort(arr, temp, mid + 1, right);
//
//		/*Merge the two parts*/
//		inv_count += merge(arr, temp, left, mid + 1, right);
//	}
//	return inv_count;
//}
//
///* This funt merges two sorted arrays
//and returns inversion count in the arrays.*/
//int merge(int arr[], int temp[], int left, int mid,
//		int right)
//{
//	int i, j, k;
//	int inv_count = 0;
//
//	i = left; /* i is index for left subarray*/
//	j = mid; /* j is index for right subarray*/
//	k = left; /* k is index for resultant merged subarray*/
//	while ((i <= mid - 1) && (j <= right)) {
//		if (arr[i] <= arr[j]) {
//			temp[k++] = arr[i++];
//		}
//		else {
//			temp[k++] = arr[j++];
//
//			/* this is tricky -- see above
//			explanation/diagram for merge()*/
//			inv_count = inv_count + (mid - i);
//		}
//	}
//
//	/* Copy the remaining elements of left subarray
//(if there are any) to temp*/
//	while (i <= mid - 1)
//		temp[k++] = arr[i++];
//
//	/* Copy the remaining elements of right subarray
//	(if there are any) to temp*/
//	while (j <= right)
//		temp[k++] = arr[j++];
//
//	/*Copy back the merged elements to original array*/
//	for (i = left; i <= right; i++)
//		arr[i] = temp[i];
//
//	return inv_count;
//}
//
//// Driver code
//int main()
//{
//	int size;
//cout<<"Enter size "; cin>>size; int arr[size];
//for(int i=0;i<size;i++)
//    cin>>arr[i];
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int ans = mergeSort(arr, n);
//	cout << " Number of inversions are " << ans;
//	return 0;
//}

// This is code is contributed by rathbhupendra
