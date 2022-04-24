#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr;
    
    int n,k; cout<<"Enter size: ";  cin>>n;
    cout<<"Enter kth number :"; cin>>k;
    
    cout<<"Enter elements:- "<<endl;
    int element{};
    for(int i=0;i<n;i++)
    {
        cin>>element; arr.push_back(element);
    }
    
    int min=arr[0];
    
    for(int i=0;i<n;i++)
    {
        if(min>arr[i])
            min=arr[i];
    }
    
    int temp{};
    int j{};
    for(int i=0;i<n && k!=0;i++)
    {
        if(min>=arr[i])
        {   temp=arr[i];
            for(j=0;j<n-1;j++)
              {  arr[j]=arr[j+1];   }
            arr[j]=temp;  n=n-1; k--;
        }
    }
    
    cout<<"Kth smallest element is: "<<arr[n-k]<<endl;
    
    return 0;
}