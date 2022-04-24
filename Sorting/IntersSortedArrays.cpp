#include <iostream>
#include <vector>
using namespace std;
/* You can either print the common elements right at the moment of implementing the logic to achieve O(1) Space complexity.*/
vector<int> intersection(vector<int> arr,vector<int> brr);

int main()
{
    vector<int>arr{1,2,4,8};
    vector<int>brr{2,4,4};
    
    vector<int> temp=intersection(arr,brr);
    cout<<"Intersection array of the two arrays is:- ";
    for(auto &i:temp)
        cout<<i<<" ";
        cout<<endl;
    return 0;
}
vector<int> intersection(vector<int> arr,vector<int> brr)
{
    int i=0,j=0;
    int n=arr.size(), m=brr.size();
    
    vector<int>temp;
    
    while(i<n && j<m)
    {
        if(i>0 && arr[i-1]==arr[i])
        {i++; continue;}
        
        if(arr[i]<brr[j])
        i++;
        else if(arr[i]>brr[j])
         j++;
        else
        { temp.push_back(arr[i]);i++;j++;}
        
    }
    
    return temp;
}