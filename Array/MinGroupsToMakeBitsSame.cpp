#include <iostream>
#include <vector>


using namespace std;
/*Minimum groups to make bits the same*/

void minGroups(bool arr[],int n);

int main()
{   
    bool arr[]={1,1,0,0,0,1,0};//ans->2 to 4 6 to 6
    
    minGroups(arr,7);
    
    return 0;
    
}

void minGroups(bool arr[],int n)
{
   
    if(n==0)
       return;
    
    if(n==1)
     {   
        cout<<"from 0 to 0"<<endl;
        return;
     }
        
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            if(arr[i]!=arr[0])//beg. of a new flip
            cout<<"from "<<i<<" to ";
            else
                cout<<i-1<<endl;
        }
        
        if(i==n-1 && arr[i]!=arr[0])
            cout<<i<<endl;
    }
    
}