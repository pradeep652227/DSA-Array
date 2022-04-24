#include <iostream>

using namespace std;
/* For last element as pivot, do the following changes :-
 *  pivot=a[ub]; while(a[start]<pivot && stat<=ub) and while(a[end]>=pivot  && end>=lb) 
 * when start>end swap(&a[ub],&a[start]); */
 
 /* For pivot element as middle= ???
   for random element:- 
   Generates Random Pivot, swaps pivot with
// end element and calls the partition function
// In Hoare partition the low element is selected
// as first pivot
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(arr[random], arr[low]);
 
    return partition(arr, low, high);
}
 * /*/
 
 
void swap(int *a,int *b){
    int c=*a, d=*b;
    c=c+d;
    d=c-d;
    c=c-d;
    
    *a=c; *b=d;
}

void partition(int arr[],int lb,int ub,int *pi);
void quicksort(int arr[],int n);
void print_array(int arr[],int n);

int main(){
    int arr[8]={8,3,5,7,6,1,4,2};
    
    cout<<"Array before sorting :- "; print_array(arr,8);
    
    quicksort(arr,8);
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

void partition(int arr[],int lb,int ub,int *pi)
{
  int start=lb, end=ub; *pi=lb;
step2:
    while( arr[end]>=arr[*pi] && (*pi)!=end)
        end--;
        
    if((*pi)==end)
        return;
    if(arr[end]<arr[*pi])
       { swap(&arr[end],&arr[*pi]); *pi=end;}
        
    goto step3;
    
   step3:  while( arr[start]<=arr[*pi] && (*pi)!=start)
        start++;
        
    if((*pi)==start)
        return;
    if(arr[start]>arr[*pi])
       { swap(&arr[start],&arr[*pi]); *pi=start;}
   
    goto step2;
    
}
//int partition(int arr[],int lb, int ub)
//{
//    int start=lb, end=ub, pivot=arr[lb];//taking pivot as the starting element
//    cout<<"pivot-> "<<pivot<<"for the array with start="<<lb<<" and end="<<ub<<" :- "; print_array(arr,8);
//    while(start<end){
//        while(arr[start]<=pivot && start<=ub)
//            start++;
//            
//        while(arr[end]>pivot && end>=lb)
//            end--;
//            
//            if(start<end)
//                swap(&arr[start],&arr[end]);
//    }
//      cout<<"Before swapping, Temporary array:- "; print_array(arr,8);
//    swap(&arr[lb],&arr[end]);
//    
//    cout<<"after swapping, Temporary array:- "; print_array(arr,8);cout<<"\n"; 
//    
//    return(end);
//}

void quicksort(int arr[],int n)
{ 
    int start,end;
    int top=-1, lower[10],upper[10]; // stacks for lower and upper bound indexes
    int pi;
    
    if(n>1)
    {
        top++;
        lower[top]=0;
        upper[top]=n-1;
    }
    
    while(top!=-1)
    {
        start=lower[top];
        end=upper[top];
        top--;
        
        partition(arr,start,end, &pi);
        
        if(start<(pi-1) )
        {
            top++; lower[top]=start; upper[top]=(pi-1);
        }
        
        if( (pi+1) < end)
        {
            top++; lower[top]= (pi+1) ; upper[top]=end;
        }
    }
     
}

