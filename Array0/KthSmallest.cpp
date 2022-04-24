#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void swap(int *a,int *b){
    int c=*a, d=*b;
    c=c+d;
    d=c-d;
    c=c-d;
    
    *a=c; *b=d;
}

void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
}

int kthSmallest(int arr[], int l, int r, int k)
{   if( l==r)
    return arr[l];
    else
    {
        int pos; int start=l,end=r,temp;
        pos=arr[(l+r)/2];
        while(start<end)
        {
            while(arr[start]<pos)
            start++;
//            cout<<"arr[start]= "<<arr[start]<<" with start= "<<start<<" "; cout<<" And array is:- "; print_array(arr,r-l+1); cout<<endl;
            while(arr[end]>pos)
            end--;
//            cout<<"arr[end]= "<<arr[end]<<" with end= "<<end<<" "; cout<<" And array is:- "; print_array(arr,r-l+1); cout<<endl; cout<<endl;
            if(start<end)
            {
                temp=arr[start];
                arr[start]=arr[end];
                arr[end]=temp;
//                    swap(&arr[start],&arr[end]);
                if(arr[start]==arr[end])
                {start++; end--;}
            }
        }
//        cout<<endl;
//        temp=start;
        
        if((k-1)>start)
       return  kthSmallest(arr,start+1,r,k);
        if((k-1)<start)
        return kthSmallest(arr,l,start-1,k);
        if((k-1)==start)
        return arr[start];
    }
}
int main()
{
// int arr[6]={7,10,4,3,20,15};   int k=kthSmallest(arr,0,n-1,3);int n=sizeof(arr)/sizeof(arr[0]);
//    print_array(arr,n);
int arr[]={8,3,5,6,1,4,9,2};  int k=4;  
int n=sizeof(arr)/sizeof(arr[0]);
    int k_value=kthSmallest(arr,0,n-1,k);
    print_array(arr,n);
     cout<<k_value<<"\t"<<arr[(n-(k-1))]<<endl;
     
return 0;

}
    

// CPP program for implementation of QuickSelect
//#include <bits/stdc++.h>
//using namespace std;
//
//// Standard partition process of QuickSort().
//// It considers the last element as pivot
//// and moves all smaller element to left of
//// it and greater elements to right
//
///*int partition(int arr[], int l, int r)
//{
//	int x = arr[r], i = l;
//	for (int j = l; j <= r - 1; j++) {
//		if (arr[j] <= x) {
//			swap(arr[i], arr[j]);
//			i++;
//		}
//	}
//	swap(arr[i], arr[r]);
//	return i;
//}*/
//
//void print_array(int arr[],int n)
//{
//    for(int i=0;i<n;i++)
//    {
//        cout<<arr[i]<<" ";
//    }
//    
//    cout<<endl;
//}
//void swap(int *a,int *b){
//    int c=*a, d=*b;
//    c=c+d;
//    d=c-d;
//    c=c-d;
//    
//    *a=c; *b=d;
//}
//int partition(int arr[],int lb, int ub)
//{
//    int start=lb, end=ub, pivot=arr[(lb+ub)/2];//taking pivot as the starting element
//    cout<<"pivot-> "<<pivot<<"for the array with start="<<lb<<" and end="<<ub<<" :- "; print_array(arr,8);
//    while(start<end){
//        while(arr[start]<pivot && start<=ub)
//            start++;
//            
//        while(arr[end]>pivot && end>=lb)
//            end--;
//            
//            if(start<end)
//              { swap(&arr[start],&arr[end]); 
//              if(arr[start]==arr[end]){ start++; end--; }
//              }
//    }
//      cout<<"Before swapping, Temporary array:- "; print_array(arr,8);
////    swap(&arr[lb],&arr[end]);
//    
//    cout<<"after swapping, Temporary array:- "; print_array(arr,8);cout<<"\n"; 
//    
//    return(end);// return (start);
//}
//
//// This function returns k'th smallest
//// element in arr[l..r] using QuickSort
//// based method. ASSUMPTION: ALL ELEMENTS
//// IN ARR[] ARE DISTINCT
//int kthSmallest(int arr[], int l, int r, int k)
//{
//	// If k is smaller than number of
//	// elements in array
//	if (k > 0 && k <= r - l + 1) {
//
//		// Partition the array around last
//		// element and get position of pivot
//		// element in sorted array
//		int index = partition(arr, l, r);
//
//		// If position is same as k
//		if (index - l == k - 1)
//			return arr[index];
//
//		// If position is more, recur
//		// for left subarray
//		if (index - l > k - 1)
//			return kthSmallest(arr, l, index - 1, k);
//
//		// Else recur for right subarray
//		return kthSmallest(arr, index + 1, r,
//							k - index + l - 1);
//	}
//
//	// If k is more than number of
//	// elements in array
//	return INT_MAX;
//}
//
//// Driver program to test above methods
//int main()
//{
//	int arr[8] = { 8,3,5,6,1,4,9,2};
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int k = 4;
//	cout << "K-th smallest element is "
//		<< kthSmallest(arr, 0, n - 1, k);
//	return 0;
//}
