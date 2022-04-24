#include <iostream>
#include <vector>

using namespace std;

long long trappingWater(int arr[], int n);

int main()
{   int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    cout<<trappingWater(arr,n);
    
    return 0;
}


long long trappingWater(int arr[],int n)
{
    
    if(n==0 || n==1)
        return 0;
        
    vector<int>rightMax(n,arr[n-1]);
    int Max{arr[n-1]};
    
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>Max)
            Max=arr[i];
        rightMax[i]=Max;
    }

    
    int leftMax{arr[0]};
    
    long long ans{};
    int temp{};
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>leftMax)
            leftMax=arr[i];
        temp=leftMax < rightMax[i]?leftMax:rightMax[i];
        
        ans+=(temp-arr[i]);
        cout<<temp<<" arr[i]= "<<arr[i]<<" temp-arr[i] "<<endl;
    }
    
    return ans;
//    vector<int>aux(n,arr[n-1]);
//    
//    int Max{arr[n-1]},Max_idx{};
//    for(int i=n-2;i>=0;i--)
//    {
//        if(arr[i]>Max)
//          {  Max=arr[i];Max_idx=i; }
//        aux[i]=Max;
//    }
//    
//    int nextMax_idx{-1};
//    if(Max_idx < n-1)
//    {
//        nextMax_idx=Max_idx + 1;
//    }
//    
//    cout<<"Max_idx is "<<Max_idx<<" and nextMax_idx is "<<nextMax_idx<<endl;
//    int start{},end{};
//    if(nextMax_idx>=0)
//    {
//        if(Max_idx - nextMax_idx <1 || nextMax_idx - Max_idx < 1)
//            return 0;
//        else
//            if(Max_idx > nextMax_idx)
//            {    end=Max_idx; start=nextMax_idx;  }
//            
//            else
//                end=nextMax_idx; start=Max_idx;
//    }
//    
//   Max=(arr[start]<arr[end])?arr[start]:arr[end];
//   
//        long long ans{};
//        
//        for(int i=start;i<=end;i++)
//        {
//            if(Max>arr[i])
//            {
//                ans+=(Max-arr[i]);
//            }
//            else
//            Max=arr[i];
//        }
//        
//        return ans;

        
}