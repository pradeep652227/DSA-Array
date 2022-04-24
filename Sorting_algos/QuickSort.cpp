#include <iostream>

using namespace std;
/* For last element as pivot, do the following changes :-
 *  pivot=a[ub]; while(a[start]<pivot && stat<=ub) and while(a[end]>=pivot  && end>=lb) 
 * when start>end swap(&a[ub],&a[start]); */
 
 /* For pivot element as middle :-
  *  pivot=arr[(lb+ub)/2]; while(start<end) {while(arr[start]<pivot && start<=ub) start++; while(arr[end]>pivot && end>=lb) end--; if(start<end){ swap(&arr[start],&arr[end]); start++;end--;} }
  * And no swapping after start > end just return end;
*/
 
void swap(int *a,int *b){
    int c=*a, d=*b;
    c=c+d;
    d=c-d;
    c=c-d;
    
    *a=c; *b=d;
}

int partition(int arr[],int lb,int ub);
void quicksort(int arr[],int lb,int ub);
void print_array(int arr[],int n);

int main(){
    int arr[8]={8,14,11,7,6,1,15,19};
    
    cout<<"Array before sorting :- "; print_array(arr,8);
    
    quicksort(arr,0,7);
    cout<<"******************"<<endl;
    cout<<"Array, after quicksort :- "; print_array(arr,8);
    
    return 0;
}

void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
}

int partition(int arr[],int lb, int ub)
{
    int start=lb, end=ub, pivot=arr[(lb+ub)/2];//taking pivot as the starting element
    cout<<"pivot-> "<<pivot<<"for the array with start="<<lb<<" and end="<<ub<<" :- "; print_array(arr,8);
    while(start<end){
        while(arr[start]<pivot && start<=ub)
            start++;
            
        while(arr[end]>pivot && end>=lb)
            end--;
            
            if(start<end)
              { swap(&arr[start],&arr[end]); 
//              if(arr[start]==arr[end]){ start++; end--; }
              }
    }
      cout<<"Before swapping, Temporary array:- "; print_array(arr,8);
//    swap(&arr[lb],&arr[end]);
    
    cout<<"after swapping, Temporary array:- "; print_array(arr,8);cout<<"\n"; 
    
    return(end);// return (start);
}

void quicksort(int arr[],int lb,int ub)
{ 
    if(lb<ub){
        int pi{};
        pi=partition(arr,lb,ub);
        quicksort(arr,lb,pi-1);
        quicksort(arr,pi+1,ub);
    }
}

