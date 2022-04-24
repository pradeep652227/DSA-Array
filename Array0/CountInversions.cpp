#include <iostream>

using namespace std;
void merge(int arr[],int l,int mid,int r);
void mergesort(int arr[],int l,int r);

int count{};
int main()
{   int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    mergesort(arr,0,n-1);
    
    cout<<"Counter :- "<<count<<endl;
    return 0;
}

void merge(int arr[],int l,int mid,int r)
{
    int i=l,j=mid+1;
    
    while(i<=mid && j<=r)
    {
        if(arr[i]>arr[j])
            count++;j++;
        if(i<mid && j>r)
        { i++; j=mid+1; }
        if(l==mid && arr[i]<arr[j])
            i++;
        if(arr[i]<arr[j] && l!=mid && j==r)
           { i++;j=mid+1; }
        else {
            j++;
        }
            
    }
    
}

void mergesort(int arr[],int l,int r)
{
   if (l<r)
   {
       int mid=(l+r)/2;
       mergesort(arr,l,mid);
       mergesort(arr,mid+1,r);
       merge(arr,l,mid,r);
   }
}