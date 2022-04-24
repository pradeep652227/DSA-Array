#include <iostream>
#include <vector>


using namespace std;
/*Element appearing more that n/2 times*/

int majority(vector<int>&arr);

int main()
{   
    int n;
    cin>>n;
    vector<int>arr;
    
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp; arr.push_back(temp);
    }
    
    cout<<"Index of Majority element is "<<majority(arr)<<endl;
    
return 0;
}

int majority(vector<int>&arr)
{
    int n=arr.size();
    
    if(n==1)
        return arr[0];
    if(n==0)
        return -1;
    
    int idx{0};
    int count{1};// considering 1st element to be the majority
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[idx])
            count++;
        else
            count--;
        if(count==0)
        {
            count=1;idx=i;
        }
    }// We've now got a candidate that may or may not be a majority one
    
    count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[idx])
            count++;
            
            if(count>n/2)
                return i;
    }
    
    return -1;
}