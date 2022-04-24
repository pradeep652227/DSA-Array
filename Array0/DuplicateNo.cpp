#include <iostream>

using namespace std;

int main()
{
//    int arr[3]{1,2,2};
//    int n=3,i=0, j=0;
//    int flag{0};// for detecting duplicate or not by changing flag value 0/1
//    for( i=0,j=n-1; i<n && j>=0;)
//    {
//        if(arr[i]==arr[j] && i!=j)
//        { flag=1; break; }
//        else if(i!=j)
//            j--;
//            else if(i==j)
//            { i++; j=n-1; }
//    }
//    
//    if(flag==1)
//    { cout<<"Duplicate found :- "<<arr[i]<<endl; }
//    else if(flag==0)
//    { cout<<"No duplicate found "<<endl; }

int nums[]{};
int N=sizeof(nums)/sizeof(nums[0]);

int n=N-1; 
if(n==1)
{
    cout<<"Duplicate element is :- 1"<<endl;
}
else if(n!=0){
    int target_sum=0;
    for(int i=1;i<=n;i++)
        target_sum+=i;
    int actual_sum=0;
    
    for(int i=0;i<N;i++)
        actual_sum+=nums[i];
    
    cout<<"Duplicate element is :- "<<(actual_sum - target_sum )<<endl;
}

else {
    cout<<"No duplicate element"<<endl;
}

    
    return 0;
}