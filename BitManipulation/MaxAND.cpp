#include <iostream>

using namespace std;

int checkPattern(int pattern, int arr[],int n);// to check the bit pattern sent by MaxAND func. and returns the number of occurences of it.
int MaxAND(int arr[], int n);

int main()
{
    int n; 
    cout<<"Enter no. of array elements "; cin>>n;
    int arr[n]; 
    cout<<"Enter the array elements"<<endl; for(int i=0;i<n;i++) cin>>arr[i];
    cout<<endl;
    
    cout<<"Max AND value of a pair of the array "; for(auto i:arr) cout<<i<<" ";
    cout<<"is\t"<<MaxAND(arr,4)<<endl;
    
    return 0;
}

int checkPattern(int pattern, int arr[],int n)
{
    int count{0};
    
    for(int i=0;i<n;i++)
    {
        if( (arr[i] & pattern) == pattern)
            count++;
    }
    
    return count;
}

int MaxAND(int arr[],int n)
{
    int ans{0}; int count{0};
    
    for(int bit=15;bit>=0;bit--)
    {
        count=checkPattern(ans | (1<<bit) , arr, n);
        
        if( count>=2 )
            ans= ans | (1<<bit) ;
    }
    
    return ans;
}